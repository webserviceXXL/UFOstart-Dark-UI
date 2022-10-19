<?php
function cactions($phase,$flightplan) {
    $count = 0;
    for ($i=0; $i < count($flightplan['records']['phase'][$phase]['topics']); $i++) {
        $count = $count + count($flightplan['records']['phase'][$phase]['topics'][$i]['actions']);
    }
    return $count;
}