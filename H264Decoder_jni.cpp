/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class H264Decoder */
#include "H264Decoder.h"


#ifndef _Included_H264Decoder
#define _Included_H264Decoder
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     H264Decoder
 * Method:    nativeH264init
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_H264Decoder_nativeH264init
  (JNIEnv *env, jobject){
      jlong result = (jlong)new H264Decoder();
      return result;
  }

/*
 * Class:     H264Decoder
 * Method:    nativeH264decode
 * Signature: (J[BI)[B
 */
JNIEXPORT jbyteArray JNICALL Java_H264Decoder_nativeH264decode
  (JNIEnv *env, jobject jobj, jlong thiz, jbyteArray frm, jint jlen){
  H264Decoder * decoder = ((H264Decoder*)thiz);
      int len = jlen;// jint is long in C++,
      jbyte* bBuffer = env->GetByteArrayElements(frm,NULL);//remeber to get element
      unsigned char * buf = (unsigned char *)bBuffer;

      decoder->decode(buf,len);
      cv::Mat result = decoder->getMat();
      if(result.data!=nullptr){

          int offset = sizeof(int)/sizeof(unsigned char);
          offset*=2;

          int matSize[2]= {result.rows,result.cols};

          int size = result.total()*result.elemSize();

          jbyteArray resultArray = env->NewByteArray(size+offset);
          jbyte* array = env->GetByteArrayElements(resultArray,JNI_FALSE);

          memcpy(array,matSize,sizeof(matSize));
          memcpy(array+offset,result.data,size);

          env->ReleaseByteArrayElements(resultArray,array,JNI_FALSE);
          return resultArray;
      }
      else{
          return nullptr;
      }
  }

#ifdef __cplusplus
}
#endif
#endif
