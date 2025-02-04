/* ================================================================
 * 版权所有 2006-2009 成都丁果科技有限公司，保留所有权利。
 * 
 * 允许对代码和二进制文件的使用、改动、再发布，但必须满足以下条件：
 * 
 * 1. 再发布的源代码，必须保留完整的版权信息。
 * 
 * 2. 再发布的二进制文件，必须产生完整的版权信息。
 * 
 * 3. 再发布版本中包括的最终用户文档，必须包括以下信息：
 * “本产品包括丁果科技所开发的软件内容。”
 * 或者，本信息可以出现在软件本身，例如第三方的声明信息中。
 *
 * 4. 使用本软件的产品，不得使用“Soft2D”或“S2D”作为产品名称，也不得在
 * 产品名称中包括“Soft2D”或“S2D”的字样，除非事先获得丁果科技的书面许可。
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


#ifndef __TEXTUREMANAGER_H__
#define __TEXTUREMANAGER_H__

//--------------------------------------------------------------------------------------------------------
#include "Common.h"
//--------------------------------------------------------------------------------------------------------
struct TexSlot
{
	Char	name[256];			// texture handle
	Texture		tex;			// texture
};
//--------------------------------------------------------------------------------------------------------
class TextureManager
{
//--------------------------------------------------------------------------------------------------------
//### interfaces:
public:
	TextureManager( void );
	~TextureManager( void );

	/// find texture, will auto load if it's not exist
	Texture*	FindOrLoadTexture( const Char* fname, const Char* path = NULL );

	/// free all textures
	void		FreeAll( void );
//--------------------------------------------------------------------------------------------------------
//### data members:
private:
	// current texture count
	s32			m_nbTextures;

	// texture pool
	TexSlot		m_TexturePool[MAX_TEXTURES];
};
//--------------------------------------------------------------------------------------------------------

#endif//__S2DENGINE_BSPTEXTUREMANAGER_H__
