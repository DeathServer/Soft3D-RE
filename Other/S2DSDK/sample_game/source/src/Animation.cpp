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

#include "../inc/Animation.h"
//--------------------------------------------------------------------------------------------------------
Animation::Animation(void) : m_pData(NULL),m_iCurFrame(0),m_bLoop(0)
{

}
//--------------------------------------------------------------------------------------------------------
Animation::~Animation(void)
{

}
void	Animation::Draw( Draw2D* pDraw2D, s32 x, s32 y  )
{
	assert( m_pData && m_iCurFrame >= 0 && m_iCurFrame<m_pData->m_nFramCnt );
	SingleAni* pAni = &m_pData->m_pData[m_iCurFrame];
	
	x +=pAni->m_iOffsetX;
	y +=pAni->m_iOffsetY;

	/// ���л�
	x -= pAni->m_pTex->GetWidth() >> 1;
	y -= pAni->m_pTex->GetHeight() >> 1;
	
	pDraw2D->SetTexture( pAni->m_pTex );
	pDraw2D->DrawOverlay( x, y );

}

void	Animation::DrawLF( Draw2D*	pDraw2D, s32 x, s32 y )
{

	assert( m_pData && m_pData->m_nFramCnt>0 );
	SingleAni* pAni;
	for( s32 i=0; i<m_pData->m_nFramCnt; i++ ){
		pAni = &m_pData->m_pData[m_iCurFrame];

		if( pAni->m_pTex ){
			pDraw2D->SetTexture( pAni->m_pTex );
			pDraw2D->DrawOverlay( x+pAni->m_iOffsetX, y+pAni->m_iOffsetY );
		}
	}
}

void	Animation::Exec( void )
{
	m_iCurFrame++;
	if( m_iCurFrame>=m_pData->m_nFramCnt ){
		if( m_bLoop ){
			m_iCurFrame = 0;
		}else{
			m_iCurFrame = m_pData->m_nFramCnt-1;
		}
	}
}

bool	Animation::IsAnimOver( void )
{
	return !m_bLoop && m_iCurFrame == m_pData->m_nFramCnt-1;
}

void	Animation::Reset( void )
{
	//m_pData = NULL;
	
	m_iCurFrame = 0;
}

void	Animation::Clone( Animation& anim )
{
	m_pData =  anim.m_pData;
	
	m_iCurFrame = anim.m_iCurFrame;

	m_bLoop =  anim.m_bLoop;
}