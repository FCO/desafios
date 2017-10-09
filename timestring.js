/*
A new task for you!

You have to create a method, that corrects a given time string. There was a problem in addition, so many of the time strings are broken. Time-Format is european. So from "00:00:00" to "23:59:59". 

Some examples:

"09:10:01" -> "09:10:01"
"11:70:10" -> "12:10:10"
"19:99:99" -> "20:40:39"
"24:01:01" -> "00:01:01"

If the input-string is null or empty return exactly this value! (empty string for C++)
If the time-string-format is invalid, return null. (empty string for C++)

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have created other katas. Have a look if you like coding and challenges.
*/

function pad(number){
	return number < 10 ? `0${number}` : number;
}

function timeCorrect(timestring) {
	if (timestring == null || timestring == '') return timestring;
	if (timestring.match(/\d{2}:\d{2}:\d{2}/) != null){
		let longTime = timestring.split(":").map(time => parseInt(time));
		let hours = longTime[0];
		let minutes = longTime[1];
		let seconds = longTime[2];
    
		if (seconds < 60){
			seconds += 0
		} else {
			seconds -= 60;
		  minutes += 1;
		}
		if (minutes < 60){
			minutes += 0
		} else {
			minutes -= 60;
		  hours += 1;
		}
		if (hours < 24){
			hours += 0
		} else {
			while(hours >= 24){
			hours -= 24;
		  }
		}
		return `${pad(hours)}:${pad(minutes)}:${pad(seconds)}`
	} else {
		return null;
	}
}
