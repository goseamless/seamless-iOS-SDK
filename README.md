seamless-iOS-SDK (v1.3.0)
==================================


Requirements
----------------------------------

- Minimum deployment target

  - iOS 6.0

- Auto Reference Counting (ARC)

  - Yes, it requires ARC.

- Frameworks

  - As of "-ObjC" flag must be defined, no need to link additional binary libraries (frameworks)  

## Installation

  * [Drag and drop](#drag-and-drop)  

## How to use  

  * [Setup](#setup)  
  * [TableView Integration](#tableview-integration)  
  * [CollectionView Integration](#collectionview-integration)  
  * [Banner Integration](#banner-integration)  
  * [Interstitial Integration](#interstitial-integration)  

## Customizing your feed ads  

  * [Feed Ad Customization](#feed-ad-customization)  

## Video Player Integration  

  * [Setup](#setup-1)  
  * [Basic Usage](#basic-usage)  
  * [Seamless Callbacks](#seamless-callbacks)  
  * [Default Video Controllers](#default-video-controllers)  
  * [Social Share Data](#social-share-data)  






Installation
----------------------------------

### Drag and drop

  1. Drag "Seamless.embeddedframework" into "Frameworks" folder.
     If folder is not visible at the left side of XCode window, you could reveal navigation bar with (command + shift + j) keyboard shortcut and find it under your project. A dialog for file adding options will appear


  ![Alt text](/ReadmeAssets/DragAndDrop/6.png "Drag & drop Seamless.embeddedframework")

  ![Alt text](/ReadmeAssets/DragAndDrop/7.png "File adding options setup dialog")


  . On dialog;

  * Create groups for any added folders and

      ![Alt text](/ReadmeAssets/DragAndDrop/dragsetupfolders.png "Select 'Create groups for any added folders and'")



  * "YourProjectName" at "Add to targets" section.

      ![Alt text](/ReadmeAssets/DragAndDrop/dragsetuptarget.png "Select <YourProjectName> at "Add to targets" section.")

    must be selected.

  2. Now, you have to add 'Other Linker Flags'. Click project navigator icon ![Alt text](/ReadmeAssets/Common/iconnavigator.png "Navigator icon") at upper-left corner (below run button)

    ! If unable to see project navigator, navigator might be closed. You could reveal navigation bar with (command + shift + j) keyboard shortcut.

  3. Select your project from project navigator

    ![Alt text](/ReadmeAssets/Common/selectproject.png "Select project")

  4. Select project target

    ![Alt text](/ReadmeAssets/Common/selecttarget.png "Select target")

  5. Select "Build settings" tab

     ![Alt text](/ReadmeAssets/Common/selectbuildsettings.png "Select 'Build Settings'")

  6. Search for "Other Linker Flags"

    ![Alt text](/ReadmeAssets/Common/searchotherlinkerflags.png "Search for 'Other Linker Flags'")

  7. Add "-ObjC" flag

    ![Alt text](/ReadmeAssets/Common/addflagobjc.png "Add linker flag '-ObjC'")

  ... and you are done.

  *To dive in coding, see **"How to use"** section below.*


How to use
----------------------------------

### Setup

  In order to use Seamless Framework properly "AppToken" parameter need to be declared on SLManager class before usage. It is recommended to perform setup on "UIApplicationDelegate" instance's "application:application didFinishLaunchingWithOptions:." selector.

  i.e

  ```Objective-C
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
    {
      // Override point for customization after application launch.

      // ...

      [[SLManager sharedManager] setAppToken:@"<Please contact seamless@mobilike.com for app token data>"];

      // ...

      return YES;
    }
  ```

  If you want to enable location based targeting, you should enable.
  ```Objective-C
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
    {
      // Override point for customization after application launch.

      // ...

      [[SLManager sharedManager] setLocationEnabled:YES];

      // ...

      return YES;
    }
  ```
  After that, if you are using Xcode 6; you should add "NSLocationWhenInUseUsageDescription" key into your Info.plist file.
![Alt text](/ReadmeAssets/Common/location.png "location")

### TableView integration

- Import required headers

  ```Objective-C
    #import <Seamless/Seamless.h>
  ```

- Declare a SLTableViewAdManager *adManager property in your view controller.

  ```Objective-C
    @property (nonatomic, strong) SLTableViewAdManager * adManager;
  ```

- In viewDidLoad; instantiate a SLTableViewAdManager, passing your tableview, data source and view controller. Data source must be NSMutableArray.

  ```Objective-C
    self.adManager = [[SLTableViewAdManager alloc] initWithTableView:self.tableView
                                                          dataSource:self.dataSource
                                                      viewController:self];
  ```
- Request ads with entity name that identifies your feeds content, category (feed contents category), and success, failure, start and finish handlers.

  ```Objective-C
     [self.adManager
     getAdsWithEntity:@"seamless-example-tableview"
     category:SLCategoryNews
     successBlock:^{
         NSLog(@"ads loaded");
     }
     failureBlock:^(NSError *error) {
         NSLog(@"%@",error);
     }];
  ```
- Add these codes into the UITableView datasource and delegate methods;

  ```Objective-C
 - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath]){
        return [self.adManager cellForRowAtIndexPath:indexPath];
    }

    // your stuff here
  }
  ```

  ```Objective-C
   - (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{

    if ([self.adManager shouldShowAdAtIndexPath:indexPath])
    {
        return [self.adManager heightForRowAtIndexPath:indexPath];
    }

    // your stuff here
   }
  ```

  ```Objective-C
  - (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath])
    {
        [self.adManager didSelectRowAtIndexPath:indexPath];
    }
    else
    {
      // your stuff here
    }
  }
  ```
- If you want to clean your dataSource (Remove all ads in your dataSource and reload your tableView);
```Objective-C
  [self.adManager cleanDataSource];
```

### CollectionView integration

- Import required headers

  ```Objective-C
    #import <Seamless/Seamless.h>
  ```

- Declare a SLCollectionViewAdManager *adManager property in your view controller.

  ```Objective-C
    @property (nonatomic, strong) SLCollectionViewAdManager * adManager;
  ```

- In viewDidLoad; instantiate a SLCollectionViewAdManager, passing your collection view, data source and view controller. Data source must be NSMutableArray.

  ```Objective-C
    self.adManager = [[SLCollectionViewAdManager alloc] initWithCollectionView:self.collectionView
                                                                    dataSource:self.dataSource
                                                                viewController:self];
   ```
- Request ads with entity name that identifies your feeds content, category (feed contents category), and success, failure, start and finish handlers.

  ```Objective-C
     [self.adManager
     getAdsWithEntity:@"seamless-example-collectionview"
     category:SLCategoryNews
     successBlock:^{
         NSLog(@"ads loaded");
     }
     failureBlock:^(NSError *error) {
         NSLog(@"%@",error);
     }];
  ```
- Add these codes into the UICollectionView datasource and delegate methods;

  ```Objective-C
  - (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath]){
        return [self.adManager cellForItemAtIndexPath:indexPath];
    }

    //your stuff here
  }
  ```

  ```Objective-C
  - (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath]){
        return [self.adManager sizeForItemAtIndexPath:indexPath];
    }

    //your stuff here
}
  ```

  ```Objective-C
  - (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath{

    if([self.adManager shouldShowAdAtIndexPath:indexPath]){
        [self.adManager didSelectItemAtIndexPath:indexPath];
    }
    else{
      //your stuff here
    }

  }
  ```

- If you want to clean your dataSource (Remove all ads in your dataSource and reload your collectionView);
```Objective-C
  [self.adManager cleanDataSource];
```

### Banner integration
  - Import required headers

  ```Objective-C
    #import <Seamless/Seamless.h>
  ```

- Declare a SLAdView *adView property in your view controller.

  ```Objective-C
    @property (nonatomic, strong) SLAdView * adView;
  ```

- In viewDidLoad; instantiate a SLAdView with your entity, category, ad size and root viewcontroller.
  Set your view controller as the adView's delegate.
  Set the adView's frame and add the adView to your controller's view hierarchy.
  Finally, load an ad by sending adView the -loadAd message.

  ```Objective-C
    self.adView = [[SLAdView alloc] initWithEntity:@"seamless-example-mma"
                                          category:SLCategoryScience
                                            adSize:SLAdSizeMMA
                                rootViewController:self];
   self.adView.delegate = self;
   CGRect frame = self.adView.frame;
   frame.origin.y = self.view.bounds.size.height - SLAdSizeMMA.height;
   self.adView.frame = frame;
   [self.view addSubview:self.adView];
   [self.adView loadAd];
   ```
- Delegate methods
  ```Objective-C
  -(void)adViewDidLoad:(SLAdView*)adView{
  // ad load success
 }

  -(void)adViewDidFailToLoad:(SLAdView*)adView{
  // ad load failed
}
  ```

### Interstitial integration
- Import required headers

  ```Objective-C
    #import <Seamless/Seamless.h>
  ```
- Declare a SLInterstitialAdManager *adManager property in your view controller.

  ```Objective-C
    @property (nonatomic, strong) SLInterstitialAdManager * adManager;
  ```
- In viewDidLoad;

```Objective-C
    self.adManager = [[SLInterstitialAdManager alloc] initWithEntity:@"interstitial-sample"  category:SLCategoryNews];
    self.adManager.delegate = self;
    [self.adManager loadAd];
```
- Add delegate methods;

```Objective-C
- (void)interstitialDidLoad:(MPInterstitialAdController *)interstitial{
  [interstitial showFromViewController:self];
}

-(void)interstitialDidFailToLoad:(MPInterstitialAdController *)interstitial{
  
}

```

### Feed Ad Customization
- If you want to customize appearance of in-feed ads you can use SLAppearance class.
- You can set your ad containers insets:

![Alt text](/ReadmeAssets/customization/3.png "Container edge insets")
```Objective-C
     SLAppearance * appearance = [[SLAppearance alloc] init];
     appearance.containerEdgeInsets = UIEdgeInsetsMake(10, 10, 10, 10);
```
>Your containers left and right insets shouldn't be greater than 22 pt!

- If your container width greater than display ads width, display ads also show in container.
You can set display ads bottom and top inset with container.

![Alt text](/ReadmeAssets/customization/4.png "display container")
```Objective-C
    appearance.displayAdBottomInset = 10.0;
    appearance.displayAdTopInset = 10.0;
```
- You can set your background colors and CTA Button image:

![Alt text](/ReadmeAssets/customization/2.png "colors")
```Objective-C
    appearance.maiaAdHeaderBackgroundColor = [UIColor lightGrayColor];  
    appearance.maiaAdFooterBackgroundColor = [UIColor grayColor];
    appearance.cellBackgroundColor = [UIColor whiteColor];
    appearance.containerBackgroundColor = [UIColor whiteColor];
    appearance.ctaButtonImage = [UIImage imageNamed:@"yourImage"];
```
- You can set your container and maia ads border line color, width and corner radius:

![Alt text](/ReadmeAssets/customization/1.png "Borders")
```Objective-C
    appearance.containerBorderWidth = 1.0;
    appearance.containerBorderLineColor = [UIColor blackColor];
    appearance.containerCornerRadius = 5.0;
    appearance.maiaAdBorderWidth = 0.5;
    appearance.maiaAdBorderLineColor = [UIColor blackColor];
    appearance.maiaAdCornerRadius = 3;
```
- For the text properties you can set font, size and text color:

![Alt text](/ReadmeAssets/customization/5.png "Texts")
```Objective-C
    appearance.maiaContainerTitleFont = [UIFont systemFontOfSize:15.0];
    appearance.maiaContainerTitleTextColor = [UIColor blackColor];
    appearance.maiaAppNameFont = [UIFont systemFontOfSize:14.0];
    appearance.maiaAppNameTextColor = [UIColor blackColor];
    appearance.maiaSponsorFont = [UIFont systemFontOfSize:11.0];
    appearance.maiaSponsorTextColor = [UIColor blackColor];
    appearance.maiaDescriptionFont = [UIFont systemFontOfSize:14.0];
    appearance.maiaDescriptionTextColor = [UIColor blackColor];
    appearance.maiaTaglineFont = [UIFont systemFontOfSize:14.0];
    appearance.maiaTaglineTextColor = [UIColor blackColor];
    appearance.maiaDownloadInfoFont = [UIFont systemFontOfSize:11.0];
    appearance.maiaDownloadInfoTextColor = [UIColor blackColor];
    appearance.maiaCTAFont = [UIFont systemFontOfSize:13.0];
    appearance.maiaCTATextColor = [UIColor blackColor];
```


- After that you can set appearance;

```Objective-C
  [self.adManager setAppearance:appearance];
```


##Player


### Setup

  In order to use Seamless Player properly "AppToken" parameter need to be decleared on SLManager class before usage. It is recommended to perform setup on "UIApplicationDelegate" instance's "application:application didFinishLaunchingWithOptions:." selector.

  i.e

  ```Objective-C
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
    {
      // Override point for customization after application launch.

      // ...

      [[SLManager sharedManager] setAppToken:@"<Please contact seamless@mobilike.com for app token data>"];

      // ...

      return YES;
    }
  ```

### Basic usage

  - As subview

    - Import required headers

      ```Objective-C
        #import <Seamless/Seamless.h>
      ```

    - Call presentation method over SLPlayerManager's shared instance with required parameters

      ```Objective-C
        NSURL *url = [NSURL URLWithString:@"<Your video content url>"];
        NSString *entity = @"<Your entity>";

        [[SLPlayerManager sharedManager]
         addPlayerToView:self.videoThumbnail
         url:url
         entity:entity];
      ```


  - As modal view controller

    - Import required headers

      ```Objective-C
        #import <Seamless/Seamless.h>
      ```

    - Call presentation method over SLPlayerManager's shared instance with required parameters

      ```Objective-C
        NSURL *url = [NSURL URLWithString:@"<Your video content url>"];
        NSString *entity = @"<Your entity>";

        [[SLPlayerManager sharedManager]
          presentPlayerWithUrl:url
          entity:entity];
      ```


### Seamless callbacks


  **If don't have comprehensive knowledge on self usage with objective-c blocks, you might want to look at https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/WorkingwithBlocks/WorkingwithBlocks.html#//apple_ref/doc/uid/TP40011210-CH8-SW16**


  All callback handlers passed within SLHandler instance

  ```Objective-C
  // Allocation & initialization of handler
  SLHandler *handler = [[SLHandler alloc] init];

  // Initialize callback handlers here. See below for more details

  // Assignment of handler
  [[SLPlayerManager sharedManager]
    // ...
    handler:handler
    // ...];

  ```

  - Presentation handler,

    . if presenting Seamless as view controller, this callback fired right after presentation animation completed.

    . if adding Seamless as subview, this callback fired right after attached to superview.

    ```Objective-C
    // Allocation & initialization of presentation handler
    handler.presentation = ^(){
      NSLog(@"Seamless presented (Available on UI)");
    };
    ```


  - Start handler, fired when user-content (non-advertisement) started playback.

    ```Objective-C
    // Allocation & initialization of start handler
    handler.start = ^(){
      NSLog(@"Seamless started");
    };
    ```


  - Progress handler, fired when user-content (non-advertisement) playback progress (current playback timestamp) altered.

    ```Objective-C
    // Allocation & initialization of progress handler
    handler.progress = ^(CGFloat currentTime, CGFloat duration){
      // Video progress updated
      NSLog(@"Seamless progress: %f / %f", currentTime, duration);
    };
    ```


  - Finish handler,

    . if presented Seamless as view controller, this callback fired right after dismiss animation completed.

    . if added Seamless as subview, this callback fired right after detached from superview.

    Finish handler callback means Seamless completed playing each content (including advertisements).

    ```Objective-C
    // Allocation & initialization of finish handler
    handler.finish = ^(){
      NSLog(@"Seamless finished (Removed from UI)");
    };
    ```


  - Error handler, fired if any error occured during playback. i.e, Timeout occured, non-supported video format provided, ...

    **If this callback fired, finish handler won't be called.**

    ```Objective-C
    // Allocation & initialization of error handler
    handler.error = ^(){
      NSLog(@"Seamless error (Removed from UI)");
    };
    ```


### Default video controllers

  - Import required headers

    ```Objective-C
      #import <Seamless/Seamless.h>
    ```

  - Pass new instance of SLDefaultVideoController to SLPlayerManager.

    ```Objective-C
      UIView *attachmentView = [SLDefaultVideoControllerView new];

      [[SLPlayerManager sharedManager]
       //...
       attachmentView:attachmentView
       // ...];
    ```

    If given, attachment view will be added to main content, content you want to play, with same size with video player's boundaries.


### Social share data

  Social share is easy to implement built-in widget, that covers Facebook, Twitter and Mail share options. These options are valid if and only if accounts enabled at device settings.

  All share data passed within SLShare instance

  ```Objective-C
  // Allocation & initialization of handler
  SLShare *share = [[SLShare alloc] init];

  // Assign share data here. See below for more details

  // Assignment of handler
  [[SLPlayerManager sharedManager]
    // ...
    share:share
    // ...];

  ```

  Available share data are;

  - Share text, takes NSString instance input as share data.
  - Share urls, takes NSArray instance. NSArray elements could be either NSURL instance or NSString instance with valid NSURL.
  - Share images, takes NSArray instance. NSArray elements could be either UIImage instance, NSURL instance of image data or NSString instance with valid image data URL.

  - Share title, takes NSString instance input as mail title. Only used when share via mail prompted.
  - Share recipients, takes NSArray instance input as share mail recipients. Only used when share via mail prompted.

  - **Social**, used when share with Facebook or Twitter prompted.
    - **Text**, takes NSString instance input as social share text
      ```Objective-C
      share.socialText = @"This text will be shared at Facebook or Twitter";
      ```
    - **Urls**, takes NSArray instance. NSArray elements could be either NSURL instance or NSString instance with valid NSURL.
      ```Objective-C
      NSString *urlString = @"http://this.is/string";
      NSURL *url = [NSURL URLWithString:@"https://this.is/url"];

      share.socialUrls = @[urlString, url];
      ```
    - **Images**, takes NSArray instance. NSArray elements could be either UIImage instance, NSURL instance of image data or NSString instance with valid image data URL.
      ```Objective-C
      NSString *urlString = @"http://this.is/string/image.png";
      NSURL *url = [NSURL URLWithString:@"https://this.is/url/image.png"];

      share.socialImages = @[urlString, url];
      ```

  - **Mail**, only used when share via mail prompted.
    - **Body**, takes NSString instance input as mail body.
    ```Objective-C
    share.mailBody = @"This text will appear at mail body";
    ```
    - **Title**, takes NSString instance input as mail title.
    ```Objective-C
    share.mailTitle = @"This text will appear at mail title";
    ```
    - **Recipients**, takes NSArray instance input as mail recipients.
    ```Objective-C
    self.mailRecipients = @[
      @"1@recipient.com",
      @"2@recipient.com"
      ];
    ```

  - **Sms**, only used when share via mail prompted.
    - **Body**, takes NSString instance input as sms body.
    ```Objective-C
    share.smsBody = @"This text will appear at sms body";
    ```
    - **Recipients**, takes NSArray instance input as mail recipients.
    ```Objective-C
    self.smsRecipients = @[
      @"123 456 78 45",
      @"+90(999)9998877",
      @"2244"
      ];
    ```
