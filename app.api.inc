<?php
/* CALL USER DATA FOR FLIGHTPLAN API */
$user = callAPI('GET', 'https://api.ufostart.com/users/current', false, $_POST['apikey']);
if(isset($user['spaceship_id'])) {
    $SpaceshipID = $user['spaceship_id'];
    $fullName = $user['full_name'];
}

if(!isset($SpaceshipID)) {
    $data = $user;
} else {
    /* CALL ACTIVE GOAL FOR GIVEN USER */
    $goal = callAPI('GET', 'https://api.ufostart.com/spaceships/'.$SpaceshipID.'/goals?limit=20&offset=0', false, $_POST['apikey']);
    $GoalsID = $goal['records'][0]['id'];

    /* CALL FLIGHTPLAN API */
    /* https://handbook.ufostart.com/reference/get-flightplan-1 */
    $flightplan = callAPI('GET', 'https://api.ufostart.com/spaceships/'.$SpaceshipID.'/goals/'.$GoalsID.'/results?limit=200&offset=0', false, $_POST['apikey']);

    $data = $flightplan;
}