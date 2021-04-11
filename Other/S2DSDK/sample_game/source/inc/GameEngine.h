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



#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

//--------------------------------------------------------------------------------------------------------
#include "Common.h"
#include "Scene.h"
#include "TextureManager.h"

//--------------------------------------------------------------------------------------------------------
class GameEngine : public Engine
{
//--------------------------------------------------------------------------------------------------------
public:
	GameEngine( void* userdata [] );
	~GameEngine( void );
//--------------------------------------------------------------------------------------------------------
//### implement Engine:
public:
	/// init all resources
	result	Init( void );

	/// free all resources
	void	Free( void );

	/// game logic before render
	void	Exec( void );

	/// game logic after render
	void	Exec2( void );

	/// pre-render proccess
	void	PreRender( void );

	/// render
	void	Render( void );

	/// post-render proccess
	void	PostRender( void );

	/// display debug info
	void	DispDebugInfo( void );

	/// define anim table
	void	DefAnimTable( void );

	/// exit game
	void		ExitGame( void );

//--------------------------------------------------------------------------------------------------------
public:
	/// ��ʼ��Ϸ
	void	EnterGame(s32 MapId);
	
	/// �ص����˵�
	void	ReturnManiUI();

	/// ��������
	void	PopMenu();
	
	/// ��ȡ�߷ְ�
	void		ReadHightScore();
	
	/// д�߷ְ�
	s32			WriteHightScore(s32 HigSc);

	/// ��������
	void		PlayMuisc(u32 ID,bool bRep);

	/// ֹͣ����
	void		StopMuisc();

	/// ��������
	void		PlaySound(u32 ID);

	/// ֹͣ����
	void		StopAllSound();

	/// ��ȡ��ͼ
	Texture*	GetTexture( const Char* name );
//--------------------------------------------------------------------------------------------------------
//### data members:
public:
	// scene
	Scene		m_Scene;


	// shaders
	FadeShader*	m_pFadeShader;


	/// �Ƿ�������
	bool			m_bUseAudio;

	///���ְ�
	s32			m_iHigScore[5];
	s32			m_iScoreScene[5];
	s32			m_iNewSceneIdex;

	
	/// �����ļ�
	AudioData*	m_pAudioData;
	s32			m_AudioCnt;

	LanguageType		m_iLanguage;

	TextureManager		m_TexMgr;
};
//--------------------------------------------------------------------------------------------------------

#endif//__GAMEENGINE_H__
