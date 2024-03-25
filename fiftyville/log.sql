-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find Crime Scene Report
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Retrieve the names and transcripts of the witnesses interviews
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

-- Find out who withdrew money from the ATM in the mentioned period of time and who left the Bakery car park in the 10 minutes after the theft.
SELECT p.name FROM people p JOIN bank_accounts AS bAccs ON p.id = bAccs.person_id JOIN atm_transactions AS atm ON atm.account_number = bAccs.account_number JOIN bakery_security_logs AS bklogs ON p.license_plate = bklogs.license_plate WHERE atm.year = 2021 AND atm.month = 7 AND atm.day = 28 AND atm.transaction_type = 'withdraw' AND bklogs.year = 2021 AND bklogs.month = 7 AND bklogs.day = 28 AND bklogs.hour = 10 AND bklogs.minute <= 25;
-- As result we narrow the list to Bruce, Diana Iman and Luca.

-- Lets find what the earliest flight was on the next day
SELECT f.id FROM flights f JOIN airports AS a ON f.origin_airport_id = a.id WHERE f.year = 2021 AND f.month = 7 AND f.day = 29 ORDER BY f.hour, f.minute LIMIT 1;
-- We find the id of the flight which was 36.

-- Who was on the flight?
SELECT p.name FROM people p JOIN passengers AS pass ON p.passport_number = pass.passport_number JOIN flights AS f ON pass.flight_id = f.id WHERE f.id = 36;
-- We can see that only Bruce was also on the previous list we found, therefore Bruce is the culprit

-- Find where Bruce went to
SELECT airP.full_name FROM airports airP JOIN flights AS f ON airP.id = f.destination_airport_id WHERE f.id = 36;
-- Find that Bruce went to LaGuardia Airport

-- Where is LaGuardia Airport?
SELECT city FROM airports WHERE full_name = 'LaGuardia Airport';
-- We find that Bruce went to New York City

-- Lets find out who Bruce called and ask to buy the flight ticket
-- first we retrieve Bruce's phone number
SELECT phone_number FROM people WHERE name = 'Bruce';

-- Check which phone number did Bruce call, with the duration under 60 seconds
SELECT receiver FROM phone_calls WHERE caller = '(367) 555-5533' AND year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- Check who that phone number belongs to -> Robin
SELECT name FROM people WHERE phone_number = '(375) 555-8161';
