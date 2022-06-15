#ifdef __ANDROID__
#include <android/native_window.h>
#include <android/native_window_jni.h>

jstring jstrclient_addr;
ANativeWindow* glsurfaceview_window;

#endif // __ANDROID__

#ifdef USE_X11
#include <X11/Xlib.h>
#include <X11/Xutil.h>

static Display *xDisplay;
static int xScreenId;
#if defined(GLS_SERVER) || !defined(USE_SERVER_SIZE)
static Window xWindow;
#endif // GLS_SERVER || !USE_SERVER_SIZE

#endif // USE_X11

#ifdef GLS_SERVER
static int glsurfaceview_width;
static int glsurfaceview_height;

static int   var_server_port;
static int   var_client_port;
const char* var_client_addr;
/*
const char* var_path_shadercache;
const char* var_file_fragment_shader;
const char* var_file_vertex_shader;
*/
// JNIEnv* glmain_jnienv;

#endif // GLS_SERVER

