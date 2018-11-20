//
// Created by Y on 2018/11/15.
//
#include <strings.h>
#include <jni.h>

static jint jni_getTestData(JNIEnv* env,jclass thiz, jobject data){
    jclass jcobs = (*env)->GetObjectClass(env, data);
    jfieldID jdata = (*env)->GetFieldID(env, jcobs, "data", "I");
    jint ji = (*env)->GetIntField(env, data, jdata);
    return ji;
}

static JNINativeMethod nativeMethods[] = {
    {"getTestData","(Lcom/ly/jnitest/TestData;)I", (void*)jni_getTestData}
};

int registerNatives(JNIEnv* env) {
    /* look up the class */
    jclass clazz = (*env)->FindClass(env, "com/ly/jnitest/AndroidJni");

    if (clazz == NULL)
       return 0;

    if ((*env)->RegisterNatives(env, clazz, nativeMethods, sizeof(nativeMethods)
	     / sizeof(nativeMethods[0])) != JNI_OK)
       return 0;

    return 1;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env = NULL;
    jint result = -1;

    (void)reserved;

    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_6) != JNI_OK)
        return -1;

    if (!registerNatives(env))
        return -1;

    /* success -- return valid version number */
    result = JNI_VERSION_1_6;

    return result;
}