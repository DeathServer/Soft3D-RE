
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

#ifndef __BUBBLE_H__
#define __BUBBLE_H__

//--------------------------------------------------------------------------------------------------------
#include "Common.h"
#include "Animation.h"

class Scene;
//--------------------------------------------------------------------------------------------------------
class Bubble
{
public:
	Bubble( void );
	~Bubble( void );

public:
	/// init scene
	bool		Init( Scene* pScene );

	void		Reset( void );

	void		Draw( Draw2D*	pDraw2D );

	void		Exec( void );

	void		Clone( Bubble& bubbe );

	/// 
	void		NormalExe( void );

	/// ������
	void		PopExe( void );

	/// ������
	void		DropExe( void );
	
	///�ƶ���
	void		MoveExe( void );
	
	/// ����
	void		Star( s32 color, f32 x, f32 y );

	/// ����
	void		Pop( void );

	/// ����
	void		Drop( void );
	
	///�ƶ�
	void		Move( f32 x, f32 y );

	///ֹͣ�ƶ�
	void		Stop(void);

	/// ������ײ
	bool		Trace( f32 x, f32 y, f32 &x2, f32 &y2 );
	
private:
	//--------------------------------------------------------------------------------------------------------
	//### data members:
	Scene*		m_pScene;
public:
	s32			m_iColor;

	BubbleState		m_eState;

	f32			m_iX;
	f32			m_iY;

	f32			m_tmpX;
	f32			m_tmpY;


	f32			m_iSpeedX;
	f32			m_iSpeedY;

	Animation*	m_pCurAni;

	Animation	m_AniNormal;
	Animation	m_AniPop;
	Animation	m_AniFailed;
};

#endif//__BUBBLE_H__
