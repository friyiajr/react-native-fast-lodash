package com.reactnativefastlodash;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = FastLodashModule.NAME)
public class FastLodashModule extends ReactContextBaseJavaModule {
    public static final String NAME = "FastLodash";

    public FastLodashModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    @NonNull
    public String getName() {
        return NAME;
    }

    @ReactMethod(isBlockingSynchronousMethod = true)
    public boolean install() {
        try {
            System.loadLibrary("cpp");
            long jsContextPointer = this.getReactApplicationContext().getJavaScriptContextHolder().get();
            installNativeJsi(jsContextPointer);
            return true;
        } catch (Exception exception) {
            return false;
        }
    }

    private native void installNativeJsi(long jsContextNativePointer);
}
