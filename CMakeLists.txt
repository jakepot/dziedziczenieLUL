cmake_minimum_required(VERSION 3.6)
project(skills)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp skill.cpp skill.h phys.cpp phys.h magic.cpp magic.h melee.cpp melee.h ranged.cpp ranged.h offence.cpp offence.h defence.cpp defence.h debuff.cpp debuff.h damage.cpp damage.h heal.cpp heal.h buff.cpp buff.h aoe.cpp aoe.h single.cpp single.h drain.cpp drain.h)
add_executable(skills ${SOURCE_FILES})