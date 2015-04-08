list(APPEND WTF_SOURCES
    gobject/GMainLoopSource.cpp
    gobject/GRefPtr.cpp
    gobject/GThreadSafeMainLoopSource.cpp
    gobject/GlibUtilities.cpp

    gtk/MainThreadGtk.cpp
    gtk/RunLoopGtk.cpp
    gtk/WorkQueueGtk.cpp
)

list(APPEND WTF_LIBRARIES
    ${GLIB_GIO_LIBRARIES}
    ${GLIB_GOBJECT_LIBRARIES}
    ${GLIB_LIBRARIES}
    pthread
    ${ZLIB_LIBRARIES}
)

if (WIN32)
    list(APPEND WTF_LIBRARIES
        winmm
    )
endif ()

list(APPEND WTF_INCLUDE_DIRECTORIES
    ${GLIB_INCLUDE_DIRS}
)
