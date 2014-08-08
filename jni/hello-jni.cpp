#include <string.h>
#include <jni.h>

/**
 * Taken from here:
 * http://taylorpeer.com/hello-world-cpp-android-ndk/
 */

extern "C" {

	/**
	 * c++ example returning a string
	 *
	 * JNIEXPORT jstring JNICALL would be a more explicit way of defining the return data type,
	 * though this appears to not be neccessary
	 */
	jstring Java_edu_usc_nsl_carma_nativecaller_NativeCaller_stringFromJNI (JNIEnv *env, jobject obj) {
		return env->NewStringUTF("Hello from C++ over JNI!");
	}

}
