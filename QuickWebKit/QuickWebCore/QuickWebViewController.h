//
//  QuickWebViewController.h
//  QuickWebViewController
//
//  Created by pcjbird on 2017/12/18.
//  Copyright © 2017年 Zero Status. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SmartJSWebView/SmartJSWebView.h>
#import "QuickWebPluginProtocol.h"
/*
 * @brief QuickWebViewController 一款基于插件的 WebView 视图控制器，您可以基于它设计您的浏览器插件，然后像积木一样来组装它们。
 */
@interface QuickWebViewController : UIViewController<SmartJSWebSecurityProxy>

/*
 * @brief webview
 */
@property(nonatomic, weak, readonly)SmartJSWebView* webView;

/*
 * @brief 所有插件
 */
@property(nonatomic, weak, readonly)NSArray<id<QuickWebPluginProtocol>>* plugins;

/*
 * @brief 导航栏是否透明
 */
@property(nonatomic, assign) BOOL navbarTransparent;

/*
 * @brief 是否显示进度条
 */
@property(nonatomic, assign) BOOL progressHidden;

/*
 * @brief 初始化
 * @param url 页面地址
 */
-(instancetype)initWithUrlString:(NSString *)url;

/*
 * @brief 加载页面
 * @param url 页面地址
 */
-(void)loadPage:(NSString *)url;

/*
 * @brief webview背景颜色 默认值：#f2f2f2
 */
-(UIColor *)backgroundColor;

/*
 * @brief webview进度条颜色 默认值：#e6001b
 */
-(UIColor *)progressColor;

/*
 * @brief webview返回按钮图标  useTextWithBackOrCloseButton返回false时有效
 */
-(UIImage *)backIndicatorImage;

/*
 * @brief webview关闭按钮图标 useTextWithBackOrCloseButton返回false时有效
 */
-(UIImage *)closeIndicatorImage;

/*
 * @brief 是否在返回或关闭按钮上使用文字  默认YES
 */
-(BOOL)useTextWithBackOrCloseButton;

/*
 * @brief 注册插件
 * @param plugin 插件
 */
- (void)registerPlugin:(id<QuickWebPluginProtocol>)plugin;

/*
 * @brief 注册通知观察者完成
 */
-(void) didRegisterNotificationObserver;

/*
 * @brief 移除通知观察者完成
 */
-(void) didRemoveNotificationObserver;

/*
 * @brief 设置导航背景色
 * @param tintColor 导航背景色, nil表示清除
 */
-(void) setBarTintColor:(UIColor*)tintColor;

/*
 * @brief 导航按钮前景色偏好
 * @return 颜色, nil表示使用全局外观设置，若全局外观设置也未设置，则使用默认色[UIColor darkGrayColor]
 */
-(UIColor *)preferNavBtnTintColor;

/*
 * @brief 导航按钮按下色(highlighted)偏好
 * @return 颜色, nil表示使用全局外观设置，若全局外观设置也未设置，则使用默认色[UIColor darkGrayColor]
 */
-(UIColor *)preferNavBtnHighlightColor;

/*
 * @brief 导航按钮前景色(disabled)偏好
 * @return 颜色, nil表示使用全局外观设置，若全局外观设置也未设置，则使用默认色[UIColor darkGrayColor]
 */
-(UIColor *)preferNavBtnDisabledColor;

@end
