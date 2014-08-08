#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>

#define DEBUG_TAG "NDK"

/**
 * Taken from here:
 * http://code.tutsplus.com/tutorials/advanced-android-getting-started-with-the-ndk--mobile-2152
 */

/**
 * Naming convention for functions writen for the NDK:
 * T Java__package-name_class-name_method-name(){}
 */

//c example accepting a string and making a call to the Android log util
void Java_edu_usc_nsl_carma_nativecaller_NativeCaller_helloLog(JNIEnv * env,
		jobject this, jstring logThis) {
	jboolean isCopy;
	const char * szLogThis = (*env)->GetStringUTFChars(env, logThis, &isCopy);

	__android_log_print(ANDROID_LOG_DEBUG, DEBUG_TAG, "NDK:LC: [%s]",
			szLogThis);

	(*env)->ReleaseStringUTFChars(env, logThis, szLogThis);
}

//c example doing some math and returning a string
jstring Java_edu_usc_nsl_carma_nativecaller_NativeCaller_getString(
		JNIEnv * env, jobject this, jint value1, jint value2) {

	char *szFormat = "The sum of the two numbers is: %i";
	char *szResult;

	// add the two values
	jlong sum = value1 + value2;

	// malloc room for the resulting string
	szResult = malloc(sizeof(szFormat) + 20);

	// standard sprintf
	sprintf(szResult, szFormat, sum);

	// get an object string
	jstring result = (*env)->NewStringUTF(env, szResult);

	// cleanup
	free(szResult);

	return result;
}
