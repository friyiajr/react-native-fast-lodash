#import <React/RCTBridgeModule.h>

#ifdef __cplusplus

#import "react-native-fast-lodash.h"

#endif

@interface FastLodash : NSObject <RCTBridgeModule>
  @property(nonatomic, assign) BOOL setBridgeOnMainQueue;
  
@end
