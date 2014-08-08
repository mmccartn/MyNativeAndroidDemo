LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog

# Discussion on compiling multiple source files:
# https://groups.google.com/forum/#!topic/android-ndk/R8q-5bFc3SA
LOCAL_MODULE    := ndk1
LOCAL_SRC_FILES := native.c hello-jni.cpp

include $(BUILD_SHARED_LIBRARY)