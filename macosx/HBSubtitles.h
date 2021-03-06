/* $Id: HBSubtitles.h,v 1.35 2005/08/01 14:29:50 titer Exp $

   This file is part of the HandBrake source code.
   Homepage: <http://handbrake.fr/>.
   It may be used under the terms of the GNU General Public License. */

#import <Cocoa/Cocoa.h>
#include "hb.h"




@interface HBSubtitles : NSObject <NSTableViewDataSource, NSTableViewDelegate> {
hb_title_t                   *fTitle;

NSMutableArray               *subtitleArray; // contains the output subtitle track info
NSMutableArray               *subtitleSourceArray;// contains the source subtitle track info
NSString                     *foreignAudioSearchTrackName;
NSMutableArray               *languagesArray; // array of languages taken from lang.c
NSInteger                     languagesArrayDefIndex;
NSMutableArray               *charCodeArray; // array of character codes
int                           charCodeArrayDefIndex;
int                           container;

}

// Trigger a refresh of data
- (void)resetWithTitle:(hb_title_t *)title;

// Create new subtitle track
- (void)addSubtitleTrack;
- (NSDictionary *)createSubtitleTrack;
- (NSMutableArray*) getSubtitleArray;
// Add an srt file
- (void)createSubtitleSrtTrack:(NSURL *)fileURL;

- (void)containerChanged:(int) newContainer;

- (void)setNewSubtitles:(NSMutableArray*) newSubtitleArray;

// Table View Delegates
- (NSUInteger)numberOfRowsInTableView:(NSTableView *)aTableView;

- (id)tableView:(NSTableView *)aTableView
      objectValueForTableColumn:(NSTableColumn *)aTableColumn
      row:(NSInteger)rowIndex;
      
- (void)tableView:(NSTableView *)aTableView
        setObjectValue:(id)anObject
        forTableColumn:(NSTableColumn *)aTableColumn
        row:(NSInteger)rowIndex;

- (void)tableView:(NSTableView *)aTableView
        willDisplayCell:(id)aCell
        forTableColumn:(NSTableColumn *)aTableColumn
        row:(NSInteger)rowIndex;

@end
