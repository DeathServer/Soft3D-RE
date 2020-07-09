# Soft3D engine archaeology

- written in C++

## File formats

- ✔️ S3DTEX = images/textures, well-understood
- ❌ S3DSTY = ?
- ❌ SAI = probably 3D model animations
- ❌ SAU = audio
- 🔧 SBN = font (glyphs) + text data, mostly understood
  - Why is the header length not always the same?
  - How to calculate glyph indexes?
- ❌ SBP = maps (Bsp)
- ❌ SDT = various _data tables_ without a common format?
  - `config.sdt`
  - `ui/state.sdt`
  - `ui/str.std` = table of textures to load for UI
- ❌ SPL = ?
- 🔧 SOJ = 3D objects, partially understood
  - How are textures mapped?
  - How are UV coordinates encoded?
  - Skinning? Animations?
- ❌ SST = “simple script”
- ✔️ STX = images/textures, well-understood

## Some links

### 7 Days

- http://legendsworld.net/adventure/game/2455
- http://www.legendsworld.net/phpBB3/viewtopic.php?f=5&t=9745
- https://imgur.com/a/3IMWR7r
- https://sourceforge.net/projects/spkextractor/

### Misc

- [Domestic "Silent Hill" IMGA award-winning mobile game-"7 Nights", can not afford the award](http://web.archive.org/web/20200709200829/http://www.1b2g.com/newsyx/1246.html) (story of the demise of Dingoo Games, in Chinese)

## Games known to use the engine

- 7 Days: Salvation
- [天地道 aka Hellstriker II](https://www.google.com/search?q=天地道+dingoo&tbm=isch) (ships on GA330)
- 斗地主 (ships on GA330)

## Platforms

- Symbian S60
- Dingoo A320
- Gemei A330
- Win32
