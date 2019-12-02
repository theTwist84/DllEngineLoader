@echo off

set version=1.1186.0.0

set is_film=true

set working_dir=D:\Games\Halo\MCC-%version%\Halo The Master Chief Collection Flighting\
set engine=HaloReach
set game_var=00_basic_editing_054
set map_var=forge_halo
set film_name=asq_cex_tim_43DC28AA

set platform=x64
set configuration=Debug
set target=DllEngineLoader

echo %working_dir%

if [%is_film%] equ [true] goto film

start "" /D "%working_dir%" /W /B "%platform%\%configuration%\%target%.exe" %engine% %game_var% %map_var%
goto eof

:film
start "" /D "%working_dir%" /W /B "%platform%\%configuration%\%target%.exe" %engine% %film_name%

:eof
pause