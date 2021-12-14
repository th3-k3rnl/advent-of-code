project('2021', 'cpp', meson_version: '>=0.60.2')

DAYS_COMPLETED = 3

include_dir = 'include\\io\\cpp'
includes = include_directories(include_dir)

subdir(include_dir)

foreach dir : range(1, DAYS_COMPLETED + 1)
    subdir(f'day@dir@')
endforeach
