#import "FastLodash.h"
#import "react-native-fast-lodash.h"


#import "FastLodash.h"
#import "react-native-fast-lodash.h"

#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#import <jsi/jsi.h>
#import <ReactCommon/CallInvoker.h>
#import <memory>

@implementation FastLodash

@synthesize bridge = _bridge;

RCT_EXPORT_MODULE()

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(install)
{
  RCTCxxBridge *cxxBridge = (RCTCxxBridge *)[RCTBridge currentBridge];
  install(*(facebook::jsi::Runtime *) cxxBridge.runtime);
  return @true;
}

+ (BOOL)requiresMainQueueSetup {
  return YES;
}

- (void)setBridge:(RCTBridge *)bridge {
  _bridge = bridge;
  _setBridgeOnMainQueue = RCTIsMainQueue();
}

@end
