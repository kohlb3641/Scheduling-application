// brendt
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Meeting
{
	int start;
	int end;
	string name;
};

/**
* simple comparison for std::sort to tell which pair has a lower value in the 2nd element.
* @param p1, p2 are the pairs used for comparison
* @return true if p1's finish time is earlier than p2.
*/
bool comparePairs(const Meeting& m1, const Meeting& m2)
{
	return m1.end < m2.end;
}

/**
* Schedules the maximum number of non-overlapping meetings.
* @param meetings a vector of pairs, where each pair represents a meeting with a start and end time.
* @return a vector of pairs representing the scheduled meetings.
*/
vector<Meeting> scheduleMeetings(vector<Meeting>* meetingsReference)
{
	vector<Meeting> meetings = *meetingsReference;
	// sort meetings using std::sort
	sort(meetings.begin(), meetings.end(), comparePairs);

	// schedule meetings
	vector<Meeting> scheduled;

	int lastEndTime = -1;
	for (Meeting meeting : meetings)
	{
		if (meeting.start >= lastEndTime) 
		{
			scheduled.push_back(meeting);
			lastEndTime = meeting.end;
		}
	}
	return scheduled;
}

void displayVisualTimeline(const vector<Meeting>& scheduled, int startHour, int endHour)
{
	cout << "--- Conference Room Timeline (8:00 - 17:00) ---" << endl;

	// Print the hour markers
	for (int i = startHour; i <= endHour; ++i)
	{
		cout << (i < 10 ? " " : "") << i << ":00 ";
	}
	cout << endl;

	// Print the meeting blocks
	vector<string> timeline(endHour - startHour, "    ");
	for (const Meeting m : scheduled)
	{
		for (int h = m.start; h < m.end; ++h)
		{
			// Map the hour to an index (8:00 is index 0)
			int index = h - startHour;
			if (index >= 0 && index < timeline.size())
			{
				string displayName = m.name.substr(0, min((int)m.name.length(), 4));
				displayName.resize(4, ' ');
				timeline[index] = displayName;
			}
		}
	}

	// Print the timeline line
	for (const string mt : timeline)
	{
		cout << "[" << mt << "]";
	}
	cout << endl;
}


// assumes input is a vector of pairs (start, end).
int main()
{

	// random test data between 8 and 17
	vector<Meeting> meetingRequests;
	vector<Meeting> scheduled;

	char again = 'y';
	int meetingStart, meetingEnd;
	string meetingName;
	int i;
	
	do {
		// output scheduled meetings, in 24-hour time

		// schedule meetings from 08:00 to 17:00 mimicking an 8-5 workday.

		// custom requests from console input

		cout << "Input meeting start time (8-16):" << endl;
		cin >> meetingStart;

		// input validation
		if (meetingStart < 8 || meetingStart > 16)
		{
			cout << "Invalid start time, the office is closed during that time." << endl;
			continue;
		}

		cout << "meeting starts at " << meetingStart << ":00." << " How long does it last? (in hours)" << endl;
		cin >> meetingEnd;

		cout << "What is the name of the meeting?" << endl;
		cin >> meetingName;

		// convert duration to end time
		meetingEnd += meetingStart;

		// input validation
		if (meetingEnd > 17)
		{
			cout << "Invalid end time, the office is closed during that time." << endl;
			continue;
		}

		// make a new pair representing the meeting and add it to the requests
		Meeting newMeeting;
		newMeeting.start = meetingStart;
		newMeeting.end = meetingEnd;
		newMeeting.name = meetingName;
		meetingRequests.push_back(newMeeting);

		scheduled = scheduleMeetings(&meetingRequests);

		// output schedule

		displayVisualTimeline(scheduled, 8, 17);


		// ask for input
		cout << "Would you like to input more meetings? (y/n): ";
		cin >> again;

	} while (again == 'y');


}
