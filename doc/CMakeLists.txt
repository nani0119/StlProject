cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME DOC)


add_custom_target(DocGen
	COMMAND  cd ${CMAKE_CURRENT_SOURCE_DIR}&&doxygen
	COMMENT "generate doc")

#install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/html/" DESTINATION doc)
