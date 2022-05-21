#include <jni.h>
#include <jsi/jsi.h>
#include <fbjni/fbjni.h>
#include <ReactCommon/CallInvokerHolder.h>
#include <typeinfo>
#include <android/log.h>

#include "react-native-fast-lodash.h"

using namespace facebook;

struct FirstModuleBridge: jni::JavaClass < FirstModuleBridge > {
    static constexpr auto kJavaDescriptor = "Lcom/reactnativefastlodash/FastLodashModule;";

    static void installNativeJsi(jni::alias_ref < jni::JObject > thiz, jlong jsiRuntimePtr) {
        auto jsiRuntime = reinterpret_cast < jsi::Runtime * > (jsiRuntimePtr);

        installMath( * jsiRuntime);
    }

    static void registerNatives() {
        javaClassStatic() -> registerNatives({ 
            makeNativeMethod("installNativeJsi", FirstModuleBridge::installNativeJsi)
        });
    }
};

JNIEXPORT jint JNI_OnLoad(JavaVM * vm, void * ) {
    __android_log_write(ANDROID_LOG_ERROR, "Tag", "Loading Android CPP Code"); 

    return jni::initialize(vm, [] {
        FirstModuleBridge::registerNatives();
    });
}