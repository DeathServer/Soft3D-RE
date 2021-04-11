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
#include "../inc/GameEngine.h"

//--------------------------------------------------------------------------------------------------------
GameEngine::GameEngine( void* userdata [] ) : 
									Engine( userdata )
{
	m_pAudioData = NULL;
}
//--------------------------------------------------------------------------------------------------------
GameEngine::~GameEngine( void )
{
	Free();
}
//--------------------------------------------------------------------------------------------------------
/// init all resources
result	GameEngine::Init( void )
{
	InitDLRes();
	// 16 FPS
	SetFPS( 24 );

	m_Scene.m_pEng = this;
	m_Scene.Init( m_pInput );

	m_pAudioData = new AudioData[15];

	m_pAudioData[Auido_bgmusic].LoadPCM( _LS("bgmusic.pcm") );
	m_pAudioData[Auido_rotate].LoadPCM( _LS("rotate.pcm") );
	m_pAudioData[Auido_cale].LoadPCM( _LS("cale.pcm") );
	m_pAudioData[Auido_pop].LoadPCM( _LS("pop.pcm") );
	m_pAudioData[Auido_tracewall].LoadPCM( _LS("tracewall.pcm") );
	m_pAudioData[Auido_tracebubble].LoadPCM( _LS("tracebubble.pcm") );
	m_pAudioData[Auido_savebubble].LoadPCM( _LS("savebubble.pcm") );
	m_pAudioData[Auido_newscore].LoadPCM( _LS("newscore.pcm") );
	m_pAudioData[Auido_failed].LoadPCM( _LS("failed.pcm") );
	m_pAudioData[Auido_click].LoadPCM( _LS("click.pcm") );
	m_pAudioData[Auido_warning].LoadPCM( _LS("warning.pcm") );
	m_pAudioData[Auido_clear].LoadPCM( _LS("clear.pcm") );
	m_pAudioData[Auido_cannotcontrol].LoadPCM( _LS("cannotcontrol.pcm") );
	m_pAudioData[Auido_mainui].LoadPCM( _LS("mainui.pcm") );
	
	PlayMuisc( Auido_mainui, true );
	return S2D_OK;
}
//--------------------------------------------------------------------------------------------------------
/// free all resources
void	GameEngine::Free( void )
{
	ReleaseDLRes();
	m_Scene.Free();
	SAFE_DELETE_ARRAY( m_pAudioData );
	m_TexMgr.FreeAll();
}
//--------------------------------------------------------------------------------------------------------
/// game logic before render
void	GameEngine::Exec( void )
{
	m_Scene.Exec();
}
//--------------------------------------------------------------------------------------------------------
/// game logic after render
void	GameEngine::Exec2( void )
{
}
//--------------------------------------------------------------------------------------------------------
/// pre-render proccess
void	GameEngine::PreRender( void )
{

}
//--------------------------------------------------------------------------------------------------------
/// render
void	GameEngine::Render( void )
{

	m_Scene.Draw( m_pDraw2D );
}
//--------------------------------------------------------------------------------------------------------
/// post-render proccess
void	GameEngine::PostRender( void )
{
}
//--------------------------------------------------------------------------------------------------------
/// display debug info
void	GameEngine::DispDebugInfo( void )
{
}

//--------------------------------------------------------------------------------------------------------
/// ������Ϸ
void		GameEngine::EnterGame( s32 MapId )
{ 

}
//--------------------------------------------------------------------------------------------------------
/// ��������
void		GameEngine::PlayMuisc(u32 ID,bool bRep)
{
	if(!m_bUseAudio){
		return;
	}
	if(ID>=m_AudioCnt){
		return;
	}
	m_pAudioPlayer->Play(&m_pAudioData[ID],0,m_pAudioData[ID].GetLength(),255,bRep);
}

//--------------------------------------------------------------------------------------------------------
/// ֹͣ����
void		GameEngine::StopMuisc()
{
	m_pAudioPlayer->Stop(0);
}
//--------------------------------------------------------------------------------------------------------
/// ��������
void		GameEngine::PlaySound(u32 ID)
{
	if(!m_bUseAudio){
		return;
	}
	if(ID>=m_AudioCnt){
		return;
	}
	for(s32 i=1;i<AudioPlayer::MaxChannels;i++){
		if(m_pAudioPlayer->GetState(i) != AUDIO_PLAYING){
			m_pAudioPlayer->Play(&m_pAudioData[ID],i,m_pAudioData[ID].GetLength(),255,false);
			return;
		}
	}
}	
/// ֹͣ����
void		GameEngine::StopAllSound()
{
	m_bUseAudio = false;

	m_pAudioPlayer->StopAll();
}


/// exit game
void		GameEngine::ExitGame( void )
{

	Exit();
}
//--------------------------------------------------------------------------------------------------------
/// ��ȡ��ͼ
Texture*	GameEngine::GetTexture( const Char* name )
{
	return m_TexMgr.FindOrLoadTexture( name );
}
//--------------------------------------------------------------------------------------------------------

