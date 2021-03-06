/*
 * Bonjour DNS-SD plugin for Cordova.
 * Allows browsing and resolving of local ad-hoc services
 *
 * jarnoh@komplex.org - March 2012
 *
 */

#import <Foundation/Foundation.h>
#import <Foundation/NSNetServices.h>

#ifdef CORDOVA_FRAMEWORK
#import <Cordova/CDVPlugin.h>
#else
#import "CDVPlugin.h"
#endif

@interface CDVBonjour : CDVPlugin <NSNetServiceBrowserDelegate, NSNetServiceDelegate> 
{
    NSString* browseCallback;
    NSString* resolveCallback;

    NSNetServiceBrowser* netServiceBrowser;
    NSNetService* currentResolve;

}

@property (nonatomic, copy) NSString* browseCallback;
@property (nonatomic, copy) NSString* resolveCallback;

@property (nonatomic, retain, readwrite) NSNetServiceBrowser* netServiceBrowser;
@property (nonatomic, retain, readwrite) NSNetService* currentResolve;

- (void)browse:(NSArray*)arguments withDict:(NSDictionary*)options;
- (void)resolve:(NSArray*)arguments withDict:(NSDictionary*)options;


@end
