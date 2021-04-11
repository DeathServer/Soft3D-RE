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
#include "../inc/Texturemanager.h"

//--------------------------------------------------------------------------------------------------------
//### interfaces:
//--------------------------------------------------------------------------------------------------------
TextureManager::TextureManager( void ) : m_nbTextures(0)
{
	memset( (Char*)m_TexturePool, 0, sizeof(m_TexturePool) );
}
//--------------------------------------------------------------------------------------------------------
TextureManager::~TextureManager( void )
{
	FreeAll();
}
//--------------------------------------------------------------------------------------------------------
/// find texture, will auto load if it's not exist
Texture*	TextureManager::FindOrLoadTexture( const Char* name, const Char* path )
{
	// look for exist
	TexSlot* tex = m_TexturePool;
	s32 i = 0;
	for( ; i<m_nbTextures; ++i, ++tex ) {
		if( s2d::strcmp( tex->name, name ) == 0 ) {
			return &tex->tex;
		}
	}

	if( i >= MAX_TEXTURES ) {//overflow
		return NULL;
	}

	// not exist, so load it

	// make full name first
	Char fname[256];
	s2d::strcpy( fname, name );
	s2d::strcat( fname, _LS(".s3dtex") );

	// get filename with path
	Char pathname[256];
	if( path == NULL ) {
		s2d::strcpy( pathname, fname );
	}
	else {
		s2d::strcpy( pathname, path );
		s2d::strcat( pathname, fname );
	}

	if( tex->tex.CreateFromFile( pathname ) != S2D_OK ) {//create texture failed
		return NULL;
	}
	s2d::strcpy( tex->name, name );
	m_nbTextures++;


	return &tex->tex;
}
//--------------------------------------------------------------------------------------------------------
/// free all textures
void		TextureManager::FreeAll( void )
{
	s32 i;
	// look for exist
	TexSlot* texs = m_TexturePool;
	for( i=0; i<m_nbTextures; ++i, ++texs ) {
		// free all
		texs->tex.Free();
	}
	m_nbTextures = 0;
}

