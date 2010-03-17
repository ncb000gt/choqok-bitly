include_directories(
${CHOQOK_INCLUDES}
)

########### next target ###############

set( choqok_bitly_SRCS
bitly.cpp )

kde4_add_plugin(choqok_bitly ${choqok_bitly_SRCS})

#kde4_add_ui_files(choqok_bitly_SRCS bitlyuploadimage_base.ui)

kde4_add_kcfg_files(choqok_bitly_SRCS bitlysettings.kcfgc )

kde4_add_plugin(choqok_bitly ${choqok_bitly_SRCS})

target_link_libraries(choqok_bitly ${KDE4_KIO_LIBS} choqok)

install(TARGETS choqok_bitly DESTINATION ${PLUGIN_INSTALL_DIR})

########### next target ###############

set( kcm_choqok_bitly_SRCS
bitlyconfig.cpp )

kde4_add_ui_files(kcm_choqok_bitly_SRCS bitlyshortnerprefs.ui )

kde4_add_kcfg_files(kcm_choqok_bitly_SRCS bitlysettings.kcfgc )

kde4_add_plugin(kcm_choqok_bitly ${kcm_choqok_bitly_SRCS})

target_link_libraries(kcm_choqok_bitly ${KDE4_KDEUI_LIBS} choqok)

install(TARGETS kcm_choqok_bitly DESTINATION ${PLUGIN_INSTALL_DIR})

########### next target ###############

install( FILES bitlysettings.kcfg  DESTINATION ${KCFG_INSTALL_DIR})
install( FILES choqok_bitly_config.desktop choqok_bitly.desktop  DESTINATION ${SERVICES_INSTALL_DIR})
install( FILES bitlyui.rc  DESTINATION  ${DATA_INSTALL_DIR}/choqok_bitly )