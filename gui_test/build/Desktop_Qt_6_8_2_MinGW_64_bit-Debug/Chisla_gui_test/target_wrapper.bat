@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\QT\6.8.2\mingw_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\QT\6.8.2\mingw_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\QT\6.8.2\mingw_64\plugins
)
%*
EndLocal
