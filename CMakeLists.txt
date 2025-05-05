cmake_minimum_required(VERSION 3.13.0)

cmake_policy(SET CMP0048 NEW) # This policy sets the VERSION variable with the project() command

project(biocreator VERSION 1.0.0 DESCRIPTION "DNA editor and biological editor that allows to create and modify real life forms" HOMEPAGE_URL "https://www.github.com/scifir/biocreator" LANGUAGES "CXX")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER_VERSION 13.2)

include(extra/FindLinuxDistribution.cmake)

if (DEFINED LINUX_LIBRARY_DIR)
	set(Boost_LIBRARY_DIR ${LINUX_LIBRARY_DIR})
endif()

if (NOT DEFINED LINUX_LIBRARY_DIR AND PLATFORM MATCHES "linux")
	set(CMAKE_LIBRARY_PATH "/usr/lib/*;/usr/lib;/usr/lib64")
endif()

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(BUILD_TESTING "Build test programs" OFF)
option(DEBUG_FLAGS "Add debug flags" OFF)
option(WARNING_FLAGS "Add warning flags" OFF)

if(DEBUG_FLAGS)
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Og")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /EHsc")
	endif()
	if(BUILD_TESTING AND (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage -lgcov")
	endif()
endif()

if(WARNING_FLAGS)
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall")
	endif()
endif()

if(DEFINED(${INCLUDE_PATH}))
	include_directories(${INCLUDE_PATH})
endif()
if(DEFINED(${LINK_PATH}))
	link_directories(${LINK_PATH})
endif()

set(Boost_NO_BOOST_CMAKE ON)
set(Boost_NO_SYSTEM_PATHS ON)
set(Boost_USE_DEBUG_LIBS        OFF)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.66.0 REQUIRED COMPONENTS system)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif()

if(!Boost_FOUND)
  message("Libraries of Boost not found, configure Boost_ variables properly and/or install Boost adequately. You can search the documentation of FindBoost, part of CMake, to learn the Boost_ variables to configure. Inside the README.md of scifir-units is also the explanation of how to configure Boost_ variables.")
endif()

find_package(ICU 70 COMPONENTS uc REQUIRED)

if(!ICU_FOUND)
	message("Library ICU not found, install it in your system first.")
endif()

aux_source_directory(ui SRC_LIST)
aux_source_directory(ui/windows SRC_LIST1)
aux_source_directory(core SRC_LIST2)
include_directories(. /usr/include/wx-3.2)

# Add that for win32 only
#set(wxWidgets_CONFIGURATION mswu)
#set(wxWidgets_ROOT_DIR /usr/include/wx-3.2)
#set(wxWidgets_LIB_DIR /usr/lib/x86_64-linux-gnu)
find_package(wxWidgets REQUIRED COMPONENTS core base adv stc aui)
include(${wxWidgets_USE_FILE})
message(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} ${SRC_LIST} ${SRC_LIST1} ${SRC_LIST2})
target_link_libraries(${PROJECT_NAME} scifir-biology scifir-chemistry scifir-units Boost::system ${ICU_LIBRARIES} ${wxWidgets_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${wxWidgets_INCLUDE_DIRS})

install(TARGETS biocreator RUNTIME DESTINATION bin)
