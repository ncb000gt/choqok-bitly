include_directories(
${CHOQOK_INCLUDES}
)

set( choqok_bitly_SRCS
bitly.cpp )

kde4_add_plugin(choqok_bitly ${choqok_bitly_SRCS})

target_link_libraries(choqok_bitly ${KDE4_KIO_LIBS} choqok)

install(TARGETS choqok_bitly DESTINATION ${PLUGIN_INSTALL_DIR})

install( FILES choqok_bitly.desktop  DESTINATION ${SERVICES_INSTALL_DIR})
