/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#ifndef CHIP_CLUSTERS_H
#define CHIP_CLUSTERS_H

#import <Foundation/Foundation.h>

typedef void (^ResponseHandler)(NSError * _Nullable error, NSDictionary * _Nullable values);

@class CHIPDevice;

NS_ASSUME_NONNULL_BEGIN

@interface CHIPBarrierControl : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)barrierControlGoToPercent:(uint8_t)percentOpen completionHandler:(ResponseHandler)completionHandler;
- (BOOL)barrierControlStop:(ResponseHandler)completionHandler;

- (BOOL)readAttributeBarrierMovingState:(ResponseHandler)completionHandler;
- (BOOL)readAttributeBarrierSafetyStatus:(ResponseHandler)completionHandler;
- (BOOL)readAttributeBarrierCapabilities:(ResponseHandler)completionHandler;
- (BOOL)readAttributeBarrierPosition:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPBasic : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)mfgSpecificPing:(ResponseHandler)completionHandler;
- (BOOL)resetToFactoryDefaults:(ResponseHandler)completionHandler;

- (BOOL)readAttributeZclVersion:(ResponseHandler)completionHandler;
- (BOOL)readAttributePowerSource:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPBinding : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)bind:(uint64_t)nodeId
              groupId:(uint16_t)groupId
           endpointId:(uint8_t)endpointId
            clusterId:(uint16_t)clusterId
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)unbind:(uint64_t)nodeId
              groupId:(uint16_t)groupId
           endpointId:(uint8_t)endpointId
            clusterId:(uint16_t)clusterId
    completionHandler:(ResponseHandler)completionHandler;

- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPColorControl : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)moveColor:(int16_t)rateX
                rateY:(int16_t)rateY
          optionsMask:(uint8_t)optionsMask
      optionsOverride:(uint8_t)optionsOverride
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveColorTemperature:(uint8_t)moveMode
                        rate:(uint16_t)rate
     colorTemperatureMinimum:(uint16_t)colorTemperatureMinimum
     colorTemperatureMaximum:(uint16_t)colorTemperatureMaximum
                 optionsMask:(uint8_t)optionsMask
             optionsOverride:(uint8_t)optionsOverride
           completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveHue:(uint8_t)moveMode
                 rate:(uint8_t)rate
          optionsMask:(uint8_t)optionsMask
      optionsOverride:(uint8_t)optionsOverride
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveSaturation:(uint8_t)moveMode
                  rate:(uint8_t)rate
           optionsMask:(uint8_t)optionsMask
       optionsOverride:(uint8_t)optionsOverride
     completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveToColor:(uint16_t)colorX
               colorY:(uint16_t)colorY
       transitionTime:(uint16_t)transitionTime
          optionsMask:(uint8_t)optionsMask
      optionsOverride:(uint8_t)optionsOverride
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveToColorTemperature:(uint16_t)colorTemperature
                transitionTime:(uint16_t)transitionTime
                   optionsMask:(uint8_t)optionsMask
               optionsOverride:(uint8_t)optionsOverride
             completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveToHue:(uint8_t)hue
            direction:(uint8_t)direction
       transitionTime:(uint16_t)transitionTime
          optionsMask:(uint8_t)optionsMask
      optionsOverride:(uint8_t)optionsOverride
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveToHueAndSaturation:(uint8_t)hue
                    saturation:(uint8_t)saturation
                transitionTime:(uint16_t)transitionTime
                   optionsMask:(uint8_t)optionsMask
               optionsOverride:(uint8_t)optionsOverride
             completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveToSaturation:(uint8_t)saturation
          transitionTime:(uint16_t)transitionTime
             optionsMask:(uint8_t)optionsMask
         optionsOverride:(uint8_t)optionsOverride
       completionHandler:(ResponseHandler)completionHandler;
- (BOOL)stepColor:(int16_t)stepX
                stepY:(int16_t)stepY
       transitionTime:(uint16_t)transitionTime
          optionsMask:(uint8_t)optionsMask
      optionsOverride:(uint8_t)optionsOverride
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)stepColorTemperature:(uint8_t)stepMode
                    stepSize:(uint16_t)stepSize
              transitionTime:(uint16_t)transitionTime
     colorTemperatureMinimum:(uint16_t)colorTemperatureMinimum
     colorTemperatureMaximum:(uint16_t)colorTemperatureMaximum
                 optionsMask:(uint8_t)optionsMask
             optionsOverride:(uint8_t)optionsOverride
           completionHandler:(ResponseHandler)completionHandler;
- (BOOL)stepHue:(uint8_t)stepMode
             stepSize:(uint8_t)stepSize
       transitionTime:(uint8_t)transitionTime
          optionsMask:(uint8_t)optionsMask
      optionsOverride:(uint8_t)optionsOverride
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)stepSaturation:(uint8_t)stepMode
              stepSize:(uint8_t)stepSize
        transitionTime:(uint8_t)transitionTime
           optionsMask:(uint8_t)optionsMask
       optionsOverride:(uint8_t)optionsOverride
     completionHandler:(ResponseHandler)completionHandler;
- (BOOL)stopMoveStep:(uint8_t)optionsMask
      optionsOverride:(uint8_t)optionsOverride
    completionHandler:(ResponseHandler)completionHandler;

- (BOOL)readAttributeCurrentHue:(ResponseHandler)completionHandler;
- (BOOL)configureAttributeCurrentHue:(uint16_t)minInterval
                         maxInterval:(uint16_t)maxInterval
                              change:(uint8_t)change
                   completionHandler:(ResponseHandler)completionHandler;
- (BOOL)reportAttributeCurrentHue:(ResponseHandler)reportHandler;
- (BOOL)readAttributeCurrentSaturation:(ResponseHandler)completionHandler;
- (BOOL)configureAttributeCurrentSaturation:(uint16_t)minInterval
                                maxInterval:(uint16_t)maxInterval
                                     change:(uint8_t)change
                          completionHandler:(ResponseHandler)completionHandler;
- (BOOL)reportAttributeCurrentSaturation:(ResponseHandler)reportHandler;
- (BOOL)readAttributeRemainingTime:(ResponseHandler)completionHandler;
- (BOOL)readAttributeCurrentX:(ResponseHandler)completionHandler;
- (BOOL)configureAttributeCurrentX:(uint16_t)minInterval
                       maxInterval:(uint16_t)maxInterval
                            change:(uint16_t)change
                 completionHandler:(ResponseHandler)completionHandler;
- (BOOL)reportAttributeCurrentX:(ResponseHandler)reportHandler;
- (BOOL)readAttributeCurrentY:(ResponseHandler)completionHandler;
- (BOOL)configureAttributeCurrentY:(uint16_t)minInterval
                       maxInterval:(uint16_t)maxInterval
                            change:(uint16_t)change
                 completionHandler:(ResponseHandler)completionHandler;
- (BOOL)reportAttributeCurrentY:(ResponseHandler)reportHandler;
- (BOOL)readAttributeDriftCompensation:(ResponseHandler)completionHandler;
- (BOOL)readAttributeCompensationText:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorTemperature:(ResponseHandler)completionHandler;
- (BOOL)configureAttributeColorTemperature:(uint16_t)minInterval
                               maxInterval:(uint16_t)maxInterval
                                    change:(uint16_t)change
                         completionHandler:(ResponseHandler)completionHandler;
- (BOOL)reportAttributeColorTemperature:(ResponseHandler)reportHandler;
- (BOOL)readAttributeColorMode:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorControlOptions:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorControlOptions:(uint8_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeNumberOfPrimaries:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary1X:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary1Y:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary1Intensity:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary2X:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary2Y:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary2Intensity:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary3X:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary3Y:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary3Intensity:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary4X:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary4Y:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary4Intensity:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary5X:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary5Y:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary5Intensity:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary6X:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary6Y:(ResponseHandler)completionHandler;
- (BOOL)readAttributePrimary6Intensity:(ResponseHandler)completionHandler;
- (BOOL)readAttributeWhitePointX:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeWhitePointX:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeWhitePointY:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeWhitePointY:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorPointRX:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorPointRX:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorPointRY:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorPointRY:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorPointRIntensity:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorPointRIntensity:(uint8_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorPointGX:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorPointGX:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorPointGY:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorPointGY:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorPointGIntensity:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorPointGIntensity:(uint8_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorPointBX:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorPointBX:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorPointBY:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorPointBY:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorPointBIntensity:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeColorPointBIntensity:(uint8_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeEnhancedCurrentHue:(ResponseHandler)completionHandler;
- (BOOL)readAttributeEnhancedColorMode:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorLoopActive:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorLoopDirection:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorLoopTime:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorCapabilities:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorTempPhysicalMin:(ResponseHandler)completionHandler;
- (BOOL)readAttributeColorTempPhysicalMax:(ResponseHandler)completionHandler;
- (BOOL)readAttributeCoupleColorTempToLevelMinMireds:(ResponseHandler)completionHandler;
- (BOOL)readAttributeStartUpColorTemperatureMireds:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeStartUpColorTemperatureMireds:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPDescriptor : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;

- (BOOL)readAttributeServer:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClient:(ResponseHandler)completionHandler;
- (BOOL)readAttributeParts:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPDoorLock : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)clearAllPins:(ResponseHandler)completionHandler;
- (BOOL)clearAllRfids:(ResponseHandler)completionHandler;
- (BOOL)clearHolidaySchedule:(uint8_t)scheduleId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)clearPin:(uint16_t)userId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)clearRfid:(uint16_t)userId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)clearWeekdaySchedule:(uint8_t)scheduleId userId:(uint16_t)userId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)clearYeardaySchedule:(uint8_t)scheduleId userId:(uint16_t)userId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)getHolidaySchedule:(uint8_t)scheduleId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)getLogRecord:(uint16_t)logIndex completionHandler:(ResponseHandler)completionHandler;
- (BOOL)getPin:(uint16_t)userId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)getRfid:(uint16_t)userId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)getUserType:(uint16_t)userId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)getWeekdaySchedule:(uint8_t)scheduleId userId:(uint16_t)userId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)getYeardaySchedule:(uint8_t)scheduleId userId:(uint16_t)userId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)lockDoor:(char *)pin completionHandler:(ResponseHandler)completionHandler;
- (BOOL)setHolidaySchedule:(uint8_t)scheduleId
                localStartTime:(uint32_t)localStartTime
                  localEndTime:(uint32_t)localEndTime
    operatingModeDuringHoliday:(uint8_t)operatingModeDuringHoliday
             completionHandler:(ResponseHandler)completionHandler;
- (BOOL)setPin:(uint16_t)userId
           userStatus:(uint8_t)userStatus
             userType:(uint8_t)userType
                  pin:(char *)pin
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)setRfid:(uint16_t)userId
           userStatus:(uint8_t)userStatus
             userType:(uint8_t)userType
                   id:(char *)id
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)setUserType:(uint16_t)userId userType:(uint8_t)userType completionHandler:(ResponseHandler)completionHandler;
- (BOOL)setWeekdaySchedule:(uint8_t)scheduleId
                    userId:(uint16_t)userId
                  daysMask:(uint8_t)daysMask
                 startHour:(uint8_t)startHour
               startMinute:(uint8_t)startMinute
                   endHour:(uint8_t)endHour
                 endMinute:(uint8_t)endMinute
         completionHandler:(ResponseHandler)completionHandler;
- (BOOL)setYeardaySchedule:(uint8_t)scheduleId
                    userId:(uint16_t)userId
            localStartTime:(uint32_t)localStartTime
              localEndTime:(uint32_t)localEndTime
         completionHandler:(ResponseHandler)completionHandler;
- (BOOL)unlockDoor:(char *)pin completionHandler:(ResponseHandler)completionHandler;
- (BOOL)unlockWithTimeout:(uint16_t)timeoutInSeconds pin:(char *)pin completionHandler:(ResponseHandler)completionHandler;

- (BOOL)readAttributeLockState:(ResponseHandler)completionHandler;
- (BOOL)configureAttributeLockState:(uint16_t)minInterval
                        maxInterval:(uint16_t)maxInterval
                  completionHandler:(ResponseHandler)completionHandler;
- (BOOL)reportAttributeLockState:(ResponseHandler)reportHandler;
- (BOOL)readAttributeLockType:(ResponseHandler)completionHandler;
- (BOOL)readAttributeActuatorEnabled:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPGroups : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)addGroup:(uint16_t)groupId groupName:(char *)groupName completionHandler:(ResponseHandler)completionHandler;
- (BOOL)addGroupIfIdentifying:(uint16_t)groupId groupName:(char *)groupName completionHandler:(ResponseHandler)completionHandler;
- (BOOL)getGroupMembership:(uint8_t)groupCount groupList:(uint16_t)groupList completionHandler:(ResponseHandler)completionHandler;
- (BOOL)removeAllGroups:(ResponseHandler)completionHandler;
- (BOOL)removeGroup:(uint16_t)groupId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)viewGroup:(uint16_t)groupId completionHandler:(ResponseHandler)completionHandler;

- (BOOL)readAttributeNameSupport:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPIasZone : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;

- (BOOL)readAttributeZoneState:(ResponseHandler)completionHandler;
- (BOOL)readAttributeZoneType:(ResponseHandler)completionHandler;
- (BOOL)readAttributeZoneStatus:(ResponseHandler)completionHandler;
- (BOOL)readAttributeIasCieAddress:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeIasCieAddress:(uint64_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeZoneId:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPIdentify : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)identify:(uint16_t)identifyTime completionHandler:(ResponseHandler)completionHandler;
- (BOOL)identifyQuery:(ResponseHandler)completionHandler;

- (BOOL)readAttributeIdentifyTime:(ResponseHandler)completionHandler;
- (BOOL)writeAttributeIdentifyTime:(uint16_t)value completionHandler:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPLevelControl : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)move:(uint8_t)moveMode
                 rate:(uint8_t)rate
           optionMask:(uint8_t)optionMask
       optionOverride:(uint8_t)optionOverride
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveToLevel:(uint8_t)level
       transitionTime:(uint16_t)transitionTime
           optionMask:(uint8_t)optionMask
       optionOverride:(uint8_t)optionOverride
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveToLevelWithOnOff:(uint8_t)level
              transitionTime:(uint16_t)transitionTime
           completionHandler:(ResponseHandler)completionHandler;
- (BOOL)moveWithOnOff:(uint8_t)moveMode rate:(uint8_t)rate completionHandler:(ResponseHandler)completionHandler;
- (BOOL)step:(uint8_t)stepMode
             stepSize:(uint8_t)stepSize
       transitionTime:(uint16_t)transitionTime
           optionMask:(uint8_t)optionMask
       optionOverride:(uint8_t)optionOverride
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)stepWithOnOff:(uint8_t)stepMode
             stepSize:(uint8_t)stepSize
       transitionTime:(uint16_t)transitionTime
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)stop:(uint8_t)optionMask optionOverride:(uint8_t)optionOverride completionHandler:(ResponseHandler)completionHandler;
- (BOOL)stopWithOnOff:(ResponseHandler)completionHandler;

- (BOOL)readAttributeCurrentLevel:(ResponseHandler)completionHandler;
- (BOOL)configureAttributeCurrentLevel:(uint16_t)minInterval
                           maxInterval:(uint16_t)maxInterval
                                change:(uint8_t)change
                     completionHandler:(ResponseHandler)completionHandler;
- (BOOL)reportAttributeCurrentLevel:(ResponseHandler)reportHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPOnOff : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)off:(ResponseHandler)completionHandler;
- (BOOL)on:(ResponseHandler)completionHandler;
- (BOOL)toggle:(ResponseHandler)completionHandler;

- (BOOL)readAttributeOnOff:(ResponseHandler)completionHandler;
- (BOOL)configureAttributeOnOff:(uint16_t)minInterval
                    maxInterval:(uint16_t)maxInterval
              completionHandler:(ResponseHandler)completionHandler;
- (BOOL)reportAttributeOnOff:(ResponseHandler)reportHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPScenes : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;
- (BOOL)addScene:(uint16_t)groupId
              sceneId:(uint8_t)sceneId
       transitionTime:(uint16_t)transitionTime
            sceneName:(char *)sceneName
            clusterId:(uint16_t)clusterId
               length:(uint8_t)length
                value:(uint8_t)value
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)getSceneMembership:(uint16_t)groupId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)recallScene:(uint16_t)groupId
              sceneId:(uint8_t)sceneId
       transitionTime:(uint16_t)transitionTime
    completionHandler:(ResponseHandler)completionHandler;
- (BOOL)removeAllScenes:(uint16_t)groupId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)removeScene:(uint16_t)groupId sceneId:(uint8_t)sceneId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)storeScene:(uint16_t)groupId sceneId:(uint8_t)sceneId completionHandler:(ResponseHandler)completionHandler;
- (BOOL)viewScene:(uint16_t)groupId sceneId:(uint8_t)sceneId completionHandler:(ResponseHandler)completionHandler;

- (BOOL)readAttributeSceneCount:(ResponseHandler)completionHandler;
- (BOOL)readAttributeCurrentScene:(ResponseHandler)completionHandler;
- (BOOL)readAttributeCurrentGroup:(ResponseHandler)completionHandler;
- (BOOL)readAttributeSceneValid:(ResponseHandler)completionHandler;
- (BOOL)readAttributeNameSupport:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN

@interface CHIPTemperatureMeasurement : NSObject

- (nullable instancetype)initWithDevice:(CHIPDevice *)device endpoint:(uint8_t)endpoint queue:(dispatch_queue_t)queue;

- (BOOL)readAttributeMeasuredValue:(ResponseHandler)completionHandler;
- (BOOL)configureAttributeMeasuredValue:(uint16_t)minInterval
                            maxInterval:(uint16_t)maxInterval
                                 change:(int16_t)change
                      completionHandler:(ResponseHandler)completionHandler;
- (BOOL)reportAttributeMeasuredValue:(ResponseHandler)reportHandler;
- (BOOL)readAttributeMinMeasuredValue:(ResponseHandler)completionHandler;
- (BOOL)readAttributeMaxMeasuredValue:(ResponseHandler)completionHandler;
- (BOOL)readAttributeClusterRevision:(ResponseHandler)completionHandler;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif /* CHIP_CLUSTERS_H */
