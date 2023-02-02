set(JSONCPP_OLDEST_VALIDATED_POLICIES_VERSION "3.8.0")
set(JSONCPP_NEWEST_VALIDATED_POLICIES_VERSION "3.13.2")
cmake_minimum_required(VERSION ${JSONCPP_OLDEST_VALIDATED_POLICIES_VERSION})

project("Hello-World")

set(CMAKE_CXX_STANDARD 20)

set(Executable
	src/main.cpp
	src/Core.h
	src/Core.cpp
	src/DateTime.h
	src/FlagHelper.h
	src/Games.h
	src/Games.cpp
	src/Hobby.h
	src/Hobby.cpp
	src/Movies.h
	src/Movies.cpp
	src/Person.h
	src/Person.cpp
	src/School.h
	src/School.cpp
	src/University.h
	src/University.cpp
)

add_executable(${PROJECT_NAME} ${Executable})

target_precompile_headers(${PROJECT_NAME} PUBLIC src/Core.h)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )

add_subdirectory(vendor)

target_link_libraries(${PROJECT_NAME} jsoncpp_static)

add_definitions("-DPATH_TO_JSON=\"${CMAKE_SOURCE_DIR}/data/\"")
