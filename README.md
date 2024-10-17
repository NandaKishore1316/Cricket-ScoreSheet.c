# Cricket-ScoreSheet.c
This program is a basic Cricket Score Sheet application written in C. It allows users to enter and manage details about batsmen and bowlers, display those details, and view a summary of the match and records. Here’s how it works:

## 1. Structures for Batsman and Bowler:
The program uses two structures, Batsman and Bowler, to store information about each player. The batsman details include their name, runs scored, balls faced, and number of fours and sixes hit. The bowler details include their name, overs bowled, runs given, and wickets taken.

## 2. Menu Options: 
Users interact with the program through a menu with seven options:
   - Enter details for a batsman.
   - Enter details for a bowler.
   - Display the details of all batsmen.
   - Display the details of all bowlers.
   - Show a match summary, including the total runs scored.
   - Display records for the top scorer and the bowler with the most wickets.
   - Exit the program.

## 3. Validation and Input: 
The program validates player names to ensure they only contain alphabetic characters. It prompts for player details and adds them to the list of batsmen or bowlers.

## 4. Display Functions: 
   - Batsmen details include name, runs, balls faced, fours, sixes, and strike rate.
   - Bowler details include name, overs, runs given, wickets, and economy rate.

## 5. Match Summary and Records:
   - The match summary shows the total runs scored by all batsmen.
   - The records section identifies the top-scoring batsman and the bowler with the most wickets.

This program is simple and console-based, designed to help record and display basic cricket match statistics.
