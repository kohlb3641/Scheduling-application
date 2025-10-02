# Scheduling-application
Scheduling application for W4V1 of algorithms design and analysis


Between EST, SD, and EFT, EFT seems to produce the most optimal results, because the earlier finish times leave the most room for future meetings, maximizing the amount of meetings that take place in a given timeframe.

In my research, I've found that real world applications involve a combination of manual configuration with some greedy implementations. Microsoft uses "Scheduling Assistant" which finds a time that is not taken up on any of the attendee's own schedules. The automatic pick feature within "scheduling assistant" uses a greedy algorithm to decide the earliest possible time for the meeting when you are available.

Google uses a greedy algorithm in identifying available time slots, and it uses a greedy interval merging approach where events are sorted by start time, then merged if they overlap.

Proposed improvements to my own scheduling would be a warning when meetings overlap, much like real world applications, and prompting the user to find a new time. I would also improve on the UI, as it's quite primitive compared to Google Calendar or Outlook's calendar.
