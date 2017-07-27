@ECHO OFF

SET SFML_include="%cd%/SFML/include"
SET SFML_lib="%cd%/SFML/lib"
SET SFML_dependencies_release=sfml-graphics-s.lib;sfml-window-s.lib;sfml-system-s.lib;sfml-audio-s.lib
SET SFML_dependencies_debug=sfml-graphics-s-d.lib;sfml-window-s-d.lib;sfml-system-s-d.lib;sfml-audio-s-d.lib
SET SFML_dependencies_common=opengl32.lib;freetype.lib;jpeg.lib;winmm.lib;gdi32.lib;openal32.lib;flac.lib;vorbisenc.lib;vorbisfile.lib;vorbis.lib;ogg.lib;ws2_32.lib
SET SFML_x86_include="%cd%/SFML_x86/include"
SET SFML_x86_lib="%cd%/SFML_x86/lib"
SET SFML_staticness=SFML_STATIC

SETLOCAL
SET /p runvs=Run Visual Studio?\n [y/n]
IF "%runvs%" EQU "y" START vs14.lnk "%cd%/TanX/TanX.sln"
START cmd.exe \k "C: && cd %cd%"