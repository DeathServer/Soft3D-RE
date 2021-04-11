/* ================================================================
 * ��Ȩ���� 2006-2009 �ɶ������Ƽ����޹�˾����������Ȩ����
 * 
 * ����Դ���Ͷ������ļ���ʹ�á��Ķ����ٷ�������������������������
 * 
 * 1. �ٷ�����Դ���룬���뱣�������İ�Ȩ��Ϣ��
 * 
 * 2. �ٷ����Ķ������ļ���������������İ�Ȩ��Ϣ��
 * 
 * 3. �ٷ����汾�а����������û��ĵ����������������Ϣ��
 * ������Ʒ���������Ƽ���������������ݡ���
 * ���ߣ�����Ϣ���Գ�����������������������������Ϣ�С�
 *
 * 4. ʹ�ñ�����Ĳ�Ʒ������ʹ�á�Soft2D����S2D����Ϊ��Ʒ���ƣ�Ҳ������
 * ��Ʒ�����а�����Soft2D����S2D�����������������Ȼ�ö����Ƽ���������ɡ�
 * 
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL DINGOO GAMES OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ====================================================================
 */ 


#include "../inc/Bubble.h"
#include "../inc/Scene.h"
#include "../inc/GameEngine.h"
Bubble::Bubble() :m_iColor(-1),
m_eState(BS_NotUse),
m_iX(I2FP(0)),
m_iY(I2FP(0)),
m_iSpeedX(I2FP(0)),
m_iSpeedY(I2FP(0)),
m_pCurAni(NULL)
{
}
Bubble::~Bubble()
{
}
bool Bubble::Init( Scene* pScene )
{
	m_pScene = pScene;
	m_AniNormal.m_bLoop = true;
	m_AniPop.m_bLoop = false;
	m_AniFailed.m_bLoop = true;
	m_AniNormal.m_pData = &m_pScene->m_BubbeAnim[ 0 ];
	m_AniPop.m_pData = &m_pScene->m_BubbePopAnim[ 0 ];
	m_AniFailed.m_pData = &m_pScene->m_BubbeFailedAnim[ 0 ];
	return true;
}

void		Bubble::Clone( Bubble& bubbe )
{
	
	m_eState =  bubbe.m_eState;

	m_iColor = bubbe.m_iColor;
	m_AniNormal.Clone( bubbe.m_AniNormal );
	m_AniPop.Clone( bubbe.m_AniPop );
	m_AniFailed.Clone( bubbe.m_AniFailed );
	
	switch( m_eState )
	{
	case BS_Droping:
	case BS_Normal:
		m_pCurAni = &m_AniNormal;
		break;
	case BS_Poping:
		m_pCurAni = &m_AniPop;
		break;
	case BS_Failed:
		m_pCurAni = &m_AniFailed;
		break;
	}
	m_iX = bubbe.m_iX;
	m_iY = bubbe.m_iY;
	m_tmpX = bubbe.m_tmpX;
	m_tmpY = bubbe.m_tmpY;
}

void		Bubble::Reset( void )
{
	m_iColor = 0;
	m_eState = BS_NotUse;
	m_iX = I2FP(0);
	m_iY = I2FP(0);
	m_iSpeedX = I2FP(0);
	m_iSpeedY = I2FP(0);
}
/// ����
void		Bubble::Star( s32 color, f32 x, f32 y  )
{
	if( color >= m_pScene->m_iMaxColorCnt ){
		m_eState = BS_NotUse;
		return;
	}
	m_iColor = color;
	m_iX = x;
	m_iY = y;
	m_AniNormal.Reset();
	m_AniPop.Reset();
	m_AniFailed.Reset();
	m_AniNormal.m_pData = &m_pScene->m_BubbeAnim[ color ];
	m_AniPop.m_pData = &m_pScene->m_BubbePopAnim[ color ];
	m_AniFailed.m_pData = &m_pScene->m_BubbeFailedAnim[ color ];
	m_pCurAni = &m_AniNormal;
	m_eState = BS_Normal;
}
void		Bubble::Draw( Draw2D*	pDraw2D )
{
	if( m_eState == BS_NotUse ){
		return;
	}
	m_pCurAni->Draw( pDraw2D, FP2I(m_iX), FP2I(m_iY) );
}
void		Bubble::Exec( void )
{
	switch( m_eState )
	{
	case BS_Normal:
		NormalExe();
		break;
	case BS_Moving:
		MoveExe();
		break;
	case BS_Poping:
		PopExe();
		break;
	case BS_Droping:
		DropExe();
		break;
	}
}
/// 
void		Bubble::NormalExe( void )
{
	if( m_pCurAni == NULL ){
		m_pCurAni =  &m_AniNormal;
	}
	m_pCurAni->Exec();
}

/// ������
void		Bubble::PopExe( void )
{
	if( m_pCurAni == NULL ){
		m_pCurAni =  &m_AniPop;
	}
	m_pCurAni->Exec();
	if( m_pCurAni->IsAnimOver() )
	{
		m_eState = BS_NotUse;
	}
}

/// ������
void		Bubble::DropExe( void )
{
	if( m_pCurAni == NULL ){
		m_pCurAni =  &m_AniNormal;
	}
	m_pCurAni->Exec();
	m_tmpX = m_iX + m_iSpeedX;
	m_tmpY = m_iY + m_iSpeedY;
	
	if(  m_pScene->TraceBottom(this) )
	{
		m_eState = BS_NotUse;
		return;
	}
	m_iX = m_tmpX;
	m_iY = m_tmpY;
}

///�ƶ���
void		Bubble::MoveExe( void )
{
	if( m_pCurAni == NULL ){
		m_pCurAni =  &m_AniNormal;
	}
	m_pCurAni->Exec();

	m_tmpX = m_iX + m_iSpeedX;
	m_tmpY = m_iY + m_iSpeedY;
	
	//�����������ײ
	if( m_pScene->TraceBubble( m_tmpX, m_tmpY, m_iX, m_iY ) )
	{
		m_pScene->BubbleStop( this );
		m_pScene->m_pEng->PlaySound( Auido_tracebubble );
		return;
	}
	s32 ref = m_pScene->TraceWall( m_tmpX, m_tmpY, m_iX, m_iY, m_iSpeedX, m_iSpeedY );
	if( ref )
	{
		if( ref == 1 ){
			m_pScene->BubbleStop( this );
		}
		m_pScene->m_pEng->PlaySound( Auido_tracewall );
		return;
	}
	m_iX = m_tmpX;
	m_iY = m_tmpY;
}
/// ����
void		Bubble::Pop( void )
{
	m_eState = BS_Poping;
	m_pCurAni = &m_AniPop;
}

/// ����
void		Bubble::Drop( void )
{
	m_eState = BS_Droping;
	m_iSpeedX = I2FP(0);
	m_iSpeedY = F2FP(10);
	m_pCurAni = &m_AniNormal;
}

///�ƶ�
void		Bubble::Move( f32 x, f32 y )
{
	m_iSpeedX = x;
	m_iSpeedY = y;
	m_eState = BS_Moving;
}
///ֹͣ�ƶ�
void		Bubble::Stop( void )
{
	m_eState = BS_Normal;
}
/// ������ײ
bool		Bubble::Trace( f32 x, f32 y, f32 &x2, f32 &y2 )
{
	s32 ix1 = FP2I(x);
	s32 iy1 = FP2I(y);
	s32 ix2 = FP2I(m_iX);
	s32 iy2 = FP2I(m_iY);
	s32 idia = FP2I(m_pScene->m_fDiameter*F2FP(0.95));
	bool btrace = (idia*idia)>(ix1-ix2)*(ix1-ix2)+(iy1-iy2)*(iy1-iy2);

	if( btrace )
	{
		f32 temp = y2 - m_iY;
		temp.data = Abs(temp.data );
		if( temp < m_pScene->m_fRadius ){
			if( x2> m_iX ){
				x2 = m_iX + m_pScene->m_fDiameter;
			}else{
				x2 = m_iX - m_pScene->m_fDiameter;
			}
			y2 = m_iY;
			return btrace;
		}
		s32 ang =atan( (x2 - m_iX )/(y2 - m_iY) );
		x2 = m_iX + m_pScene->m_fDiameter*sin( ang );
		y2 = m_iY + m_pScene->m_fDiameter*cos( ang );
	}

	return btrace;
}
