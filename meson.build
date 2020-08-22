project('autohop', ['c'], version : 'v0.10', meson_version : '>= 0.47')

compiler = meson.get_compiler('cpp')

if target_machine.system() == 'windows'
	add_global_link_arguments('-static', language: ['cpp', 'c'])
endif

subdir('src')

executable('autohop', src)