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


#ifndef __SCENE_H__
#define __SCENE_H__

//--------------------------------------------------------------------------------------------------------
#include "Common.h"
#include "Bubble.h"

class GameEngine;
//--------------------------------------------------------------------------------------------------------
class Scene
{
public:
	Scene( void );
	~Scene( void );

public:
	/// init scene
	bool		Init( Input* pInput );

	/// init scene
	void		Reset();
	
	/// free scene
	void		Free( void );

	/// Draw scene
	void		Draw( Draw2D* pDraw2d );

	/// update scene;
	void		Exec( void );

	// ��ȡ����
	Input*		GetInput( void );

	/// ���붯��
	void		LoadAnim( const Char* name, AniData& data );

	/// ����Ϸ
	void			NewGame( Difficulty diff );

	/// ��Ϸ����
	void			EndGame();

	/// ��Ϸʧ��
	void			FaidedGame();

	/// �������һ��
	void			CreateLine( s32 r );

	/// ��ѡ��˵�
	void			UpDataMenu( );

	/// ��ѡ��˵�
	void			DrawMenu( Draw2D* pDraw2d );
	
	/// ��������
	void			PopBubble( s32 c, s32 r );

	/// ������Ա��Ƶ���������
	s32				CountSamePop( s32 c, s32 r, s32 color);
	
	// �������յ�����
	void			DropBubble( void );

	/// ��ǻ���������
	bool			MarkDrop( s32 c, s32 r );

	/// ��������
	void			CaleShoot();

	///�޸ķ���Ƕ�
	void		ControlAngles( void );

	/// �������кţ��õ�������Ļ����
	void		GetBubbleCenter( s32 c, s32 r, f32& x, f32& y );	

	/// ������Ļ���꣬�õ��������к�
	void		GetBubblePos( s32& c, s32& r, f32 x, f32 y );	

	/// ���������
	s32			Rand( s32 min, s32 max );
	
	/// ��ǽ��ײ
	s32			TraceWall( f32 x, f32 y, f32 &x2, f32 &y2, f32& speedx, f32& speedy );

	/// ������������ײ
	bool		TraceBubble( f32 x, f32 y, f32 &x2, f32 &y2 );
	
	/// �͵ײ���ײ
	bool		TraceBottom( Bubble* pBubble );

	/// ��������ֹͣ
	void		BubbleStop( Bubble* pBubble );

	/// ��������
	void		DrawCaleLine( Draw2D* pDraw2d );

	/// �����µ�������ȥ
	bool		CaleNewBubble( void );

	/// ��������
	void		SaveBubble( void );

	/// �����Ѷ�
	void		Levelup( void );

	/// ��ȡ�߷ְ�
	void		ReadHightScore();

	/// д�߷ְ�
	void		WriteHightScore(s32 HigSc);

	/// ������
	void		DrawDigital( Draw2D* pDraw2d, s32 digital, s32 x, s32 y, s32 type );

	/// ���������ļ�
	void		ReadConfig( void );
private:

	//--------------------------------------------------------------------------------------------------------
	//### data members:
public:
	
			/// �����ɫ����
    enum{
		m_iMaxColorCnt = 7,
	};
	/// ��ǰ״̬
	SceneState			m_eState;
	SceneState			m_eStateTemp;
	

	/// scene rect
	Rect		m_SceneRect;

	/// ��ǰ����
	s32				m_iScore;

	/// ��ǰ�ȼ�
	s32				m_iLevel;

	/// �����ӵķ���
	s32				m_iAddScore;

	///���ӷ���λ��
	s32				m_iAddScX;
	s32				m_iAddScY;
	s32				m_iAddCnt;

	/// ���ݰ뾶
	f32			m_fRadius;

	/// ����ֱ��
	f32			m_fDiameter;

	/// �Ѷ�
	Difficulty		m_eDifficulty;

	/// ��������ʱ��
	s32				m_iGrowTime;
	s32				m_iCntGrow;

	/// ��Ϸ��UI
	s32			m_bShowUI;

	s32			m_UICurSele;
	
	// ����
	s32			m_nOfColumns;
	// ����
	s32			m_nOfRows;

	/// ��ż�б�־
	s32			m_level;
	
	/// ��������
	s32			m_nOfBubble;
	///����
	Bubble*		m_pBubbleBuffer;
	
	/// �ȴ����������
	Bubble		m_CaleBubble;

	/// Ԥ������
	Bubble		m_ReadyBubble[2];

	/// �����µ�����
	//Bubble		m_NewBubble;
	s32			m_iCaleCnt;
	s32			m_iCntNewBubble;

	/// �洢������
	Bubble		m_SaveBubble;

	// ����λ��
	AniData		m_BubblePalce;
	
	/// ��ǰ׼������Ƕ�
	s32			m_iAngles;

	/// ���ݷ�����ٶ�
	f32			m_fCaleSpeed;
	
	// ������
	Texture*	m_pTexCaleLine;

	/// ����ȴ�ʱ��
	s32			m_iWaitTime;

	/// ���������ͣ����λ��
	s32			m_newBubleC;
	s32			m_newBubleR;

	/// ��ǰ��ɫ����
	s32			m_iCurColorCnt;
	

	/// ������Դ�б�
	AniData		m_BubbeAnim[ m_iMaxColorCnt ];
	AniData		m_BubbePopAnim[ m_iMaxColorCnt ];
	AniData		m_BubbeFailedAnim[ m_iMaxColorCnt ];
	AniData		m_AniTable[ MAX_ANIMATION ];

	/// �����б�
	Animation	m_AnimationTable[ MAX_ANIMATION ];

	/// �Ƿ�ȫ����
	s32			m_bAllClear;
	
	// ����
	Texture*	m_pTexBack;
	Texture*	m_pTexLogo;
	Texture*	m_pTexHS;

	/// input
	Input*		m_pInput;

	///
	GameEngine* m_pEng;
	
	RandomGenerator	m_rand;
	
	/// �߷ְ�
	s32				m_iCntHS;
	s32				m_iNewScoreIdex;
	s32*			m_iHightScore;
	s32				m_iFramCnt1;

	// ������ͼ
	Texture*		m_pDigital[4];

};

#endif//__SCENE_H__
