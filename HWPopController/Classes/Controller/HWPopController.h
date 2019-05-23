//
//  HWPopController.h
//  HWPopController
//
//  Created by heath wang on 2019/5/21.
//

#import <Foundation/Foundation.h>
#import <HWPopController/HWPopControllerAnimationProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, HWPopPosition) {
	HWPopPositionCenter,
	HWPopPositionTop,
	HWPopPositionBottom,
};

typedef NS_ENUM(NSInteger, HWPopControllerState) {
    HWPopControllerStatePop,
    HWPopControllerStateDismiss,
};

typedef NS_ENUM(NSInteger, HWPopType) {
    HWPopTypeNone,
    HWPopTypeFadeIn,
    HWPopTypeGrowIn,
    HWPopTypeShrinkIn,
    HWPopTypeSlideInFromTop,
    HWPopTypeSlideInFromBottom,
    HWPopTypeSlideInFromLeft,
    HWPopTypeSlideInFromRight,
    HWPopTypeBounceIn,
    HWPopTypeBounceInFromTop,
    HWPopTypeBounceInFromBottom,
    HWPopTypeBounceInFromLeft,
    HWPopTypeBounceInFromRight,
};

typedef NS_ENUM(NSInteger, HWDismissType) {
    HWDismissTypeNone,
    HWDismissTypeFadeOut,
    HWDismissTypeGrowOut,
    HWDismissTypeShrinkOut,
    HWDismissTypeSlideOutFromTop,
    HWDismissTypeSlideOutFromBottom,
    HWDismissTypeSlideOutFromLeft,
    HWDismissTypeSlideOutFromRight,
    HWDismissTypeBounceOut,
    HWDismissTypeBounceOutFromTop,
    HWDismissTypeBounceOutFromBottom,
    HWDismissTypeBounceOutFromLeft,
    HWDismissTypeBounceOutFromRight,
};

@interface HWPopController : NSObject

#pragma mark - config properties

/**
 //////////////////////////////////////////////////////
 Below props should be set when you pop the controller.
 //////////////////////////////////////////////////////
 */
/**
 * pop animation style
 * default is HWPopTypeGrowIn
 */
@property (nonatomic, assign) HWPopType popType;
/**
 * dismiss animation style
 * default is HWDismissTypeFadeOut
 */
@property (nonatomic, assign) HWDismissType dismissType;
/**
 * animation duration
 * default is 0.2 s
 */
@property (nonatomic, assign) NSTimeInterval animationDuration;

/**
 * The pop view final position.
 * Default is HWPopPositionCenter
 */
@property (nonatomic, assign) HWPopPosition popPosition;

/**
 * The offset of the pop view.
 */
@property (nonatomic, assign) CGPoint positionOffset;
/**
 * You can custom your own animation for pop and dismiss.
 * once you set this property, and NOT nil,
 * the `popType` and `dismissType` will be ignore.
 */
@property (nonatomic, weak) id<HWPopControllerAnimationProtocol> animationProtocol;
@property (nonatomic, assign) UIEdgeInsets safeAreaInsets;

/**
 //////////////////////////////////////////////////////
 Below props can be set when you need.
 //////////////////////////////////////////////////////
 */
@property (nullable, nonatomic, strong) UIView *backgroundView;
/**
 * pop background alpha.
 * default is 0.5
 */
@property (nonatomic, assign) CGFloat backgroundAlpha;
/**
 * determine touch background to dismiss
 * Default is YES.
 */
@property (nonatomic, assign) BOOL shouldDismissOnBackgroundTouch;

#pragma mark - readonly properties

@property (nonatomic, strong, readonly) UIView *containerView;
@property (nonatomic, strong, readonly) UIView *contentView;

/**
 * topViewController is the viewController which is presented.
 */
@property (nonatomic, strong, readonly) UIViewController *topViewController;
@property (nonatomic, assign, readonly) BOOL presented;

- (instancetype)initWithRootViewController:(UIViewController *)rootViewController;

- (void)presentInViewController:(UIViewController *)viewController;

- (void)presentInViewController:(UIViewController *)viewController completion:(nullable void (^)(void))completion;

- (void)dismiss;

- (void)dismissWithCompletion:(nullable void (^)(void))completion;

- (void)layoutContainerView;

@end

NS_ASSUME_NONNULL_END