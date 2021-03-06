#import <AVFoundation/AVBase.h>
#import <AVFoundation/AVAssetTrack.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>

@import AVFoundation;
@import JavaScriptCore;

@protocol JSBAVCompositionTrack;

@protocol JSBAVMutableCompositionTrack <JSExport, JSBAVCompositionTrack>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

@property (nonatomic) float preferredVolume;
@property (nonatomic) CGAffineTransform preferredTransform;
@property (nonatomic, copy) NSString *extendedLanguageTag;
@property (nonatomic, copy) NSString *languageCode;
@property (nonatomic, copy, readonly) NSArray *segments;
@property (nonatomic) CMTimeScale naturalTimeScale;

- (BOOL)insertTimeRange:(CMTimeRange)timeRange ofTrack:(AVAssetTrack *)track atTime:(CMTime)startTime error:(NSError **)error;
- (BOOL)insertTimeRanges:(NSArray *)timeRanges ofTracks:(NSArray *)tracks atTime:(CMTime)startTime error:(NSError **)error;
- (void)insertEmptyTimeRange:(CMTimeRange)timeRange;
- (void)removeTimeRange:(CMTimeRange)timeRange;
- (void)scaleTimeRange:(CMTimeRange)timeRange toDuration:(CMTime)duration;
- (BOOL)validateTrackSegments:(NSArray *)trackSegments error:(NSError **)error;

#pragma clang diagnostic pop

@end
