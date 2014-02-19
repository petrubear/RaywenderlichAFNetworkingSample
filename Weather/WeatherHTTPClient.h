//
//  WeatherHTTPClient.h
//  Weather
//
//  Created by Edison Martinez on 2/19/14.
//  Copyright (c) 2014 Scott Sherwood. All rights reserved.
//

#import "AFHTTPClient.h"
@protocol WeatherHttpClientDelegate;

@interface WeatherHTTPClient : AFHTTPClient

@property(weak) id<WeatherHttpClientDelegate> delegate;

+ (WeatherHTTPClient *)sharedWeatherHTTPClient;
- (id)initWithBaseURL:(NSURL *)url;
- (void)updateWeatherAtLocation:(CLLocation *)location forNumberOfDays:(int)number;

@end

@protocol WeatherHttpClientDelegate <NSObject>
-(void)weatherHTTPClient:(WeatherHTTPClient *)client didUpdateWithWeather:(id)weather;
-(void)weatherHTTPClient:(WeatherHTTPClient *)client didFailWithError:(NSError *)error;
@end