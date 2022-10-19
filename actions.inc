<?php
$phases = ['START','PROFESSIONALIZE','GROWTH/SCALE'];

include 'app.curl.inc';
include 'app.api.inc';
include 'app.func.inc';
?>

<?php if(isset($flightplan)) { ?>
<!-- Container-fluid -->
<div class="container-fluid">
    <div class="row row-eq-spacing-sm justify-content-center">
        
        <!-- Ful-width column with title -->
        <div class="col-12">
            <div class="content">
                <h1 class="content-title font-size-22 font-weight-semi-bold text-primary text-center text-uppercase text-extra-letter-spacing">Your Flightplan</h1>
                <p></p>
            </div>
        </div>

        <!-- Column with the side content -->
        <div class="col-12 col-lg-3 d-lg-block">
            <div class="content">
                <a href="#phase1" class="card d-block">
                    <p class="font-size-14 text-uppercase mb-0">Phase 1</p>
                    <h3 class="card-title text-bold">Start</h3>
                    <span class="text-monospace font-size-12"><?=cactions($phases[0],$flightplan)?> recommendations</span>
                </a>
                <a href="#phase2" class="card d-block">
                    <p class="font-size-14 text-uppercase mb-0">Phase 2</p>
                    <h3 class="card-title text-bold">Professionalize</h3>
                    <span class="text-monospace font-size-12"><?=cactions('PROFESSIONALIZE',$flightplan)?> recommendations</span>
                </a>
                <a href="#phase3" class="card d-block">
                    <p class="font-size-14 text-uppercase mb-0">Phase 3</p>
                    <h3 class="card-title text-bold">Scale</h3>
                    <span class="text-monospace font-size-12"><?=cactions('GROWTH/SCALE',$flightplan)?> recommendations</span>
                </a>
            </div>
        </div>

        <!-- Column with the main content -->
        <div class="col-12 col-lg-9">
            <div class="content">
            <?php
            foreach ($phases as $index=>$phase) {
                echo '<h2 id="phase'.($index + 1).'" class="content-title font-size-20 mt-20 ml-20 pl-10"><b>Phase '.($index + 1).'</b>: '.$phase.' <span class="badge badge-primary badge-pill align-middle ml-5">'.cactions($phases[$index],$flightplan).'</badge></h2>';
                for ($i = 0; $i < count($flightplan['records']['phase'][$phase]['topics']); $i++)
                {
                    echo '<div class="">';
                    for ($a = 0; $a < count($flightplan['records']['phase'][$phase]['topics'][$i]['actions']); $a++)
                    {
                        // TODO: Get Attribute Information
                        //$attr = callAPI('GET', 'https://api.ufostart.com/users/current', false, $_POST['apikey']);

                        $status = ($flightplan['records']['phase'][$phase]['topics'][$i]['actions'][$a]['status'] == 'done') ? true : false;

                        echo '<div class="card p-0 d-flex">';
                            echo '<div class="flex-grow-1 overflow-y-hidden d-flex align-items-center position-relative">';
                                echo '<div class="p-20 w-full m-auto">';
                                    echo '<span class="badge bg-dark-dm text-muted mb-5 mt-5">'.$flightplan['records']['phase'][$phase]['topics'][$i]['name'].'</span>';
                                    echo '<h3 class="card-title text-white-dm mb-5">'.$flightplan['records']['phase'][$phase]['topics'][$i]['actions'][$a]['name'].'</h3>';
                                    echo '<p class="text-muted mt-5">'.$flightplan['records']['phase'][$phase]['topics'][$i]['actions'][$a]['description'].'</p>';

                                    echo '<div class="row mt-20">';
                                        echo '<div class="col-6">';
                                            echo '<span class="badge badge-pill badge--prio"> Priority: '.str_repeat('❕',$flightplan['records']['phase'][$phase]['topics'][$i]['actions'][$a]['priority']).'</span> ';
                                            echo '<span class="badge badge-pill badge--effort"> Effort: '.str_repeat('🥵',$flightplan['records']['phase'][$phase]['topics'][$i]['actions'][$a]['effort']).'</span>';
                                        echo '</div>';
                                        echo '<div class="col-6">';
                                            echo '<div class="text-right">';
                                                echo ($flightplan['records']['phase'][$phase]['topics'][$i]['actions'][$a]['url']!="") ? '<a href="'.$flightplan['records']['phase'][$phase]['topics'][$i]['actions'][$a]['url'].'" class="btn btn-sm" target="_blank" rel="noopener">Learn more <svg class="ext" xmlns="http://www.w3.org/2000/svg" stroke-width="10" stroke-dashoffset="0" stroke-dasharray="0" stroke-linecap="round" stroke-linejoin="round" viewBox="0 0 100 100"><polyline fill="none" points="40 20 20 20 20 90 80 90 80 60"/><polyline fill="none" points="60 10 90 10 90 40"/><line fill="none" x1="89" y1="11" x2="50" y2="50" /></svg></a> ' : '';
                                                echo '<button class="btn btn-sm disabled" type="button" data-toggle="tooltip" data-title="Coming soon..." data-placement="left">Mark as done</button>';
                                            echo '</div>';
                                        echo '</div>';
                                    echo '</div>';
                                echo '</div>';
                            echo '</div>';
                            
                            $imgsize = "170";
                            echo '<div class="w-'.$imgsize.' h-'.$imgsize.' p-10 pb-5 pl-0 align-self-center"><img src="https://picsum.photos/seed/'.urlencode($flightplan['records']['phase'][$phase]['topics'][$i]['name']).'/'.$imgsize.'" class="img-fluid rounded-right" alt="..."></div>';
                            //echo '"Status": '.$status;
                        echo '</div>';
                    }
                    echo '</div>';
                }
            }
            ?>
            </div>
        </div>
    </div>
</div>
<?php } else { ?>
    <div class="container">
        <div class="row">
            <div class="col">
                <pre><?=print_r($data)?></pre>
            </div>
        </div>    
    </div>
<?php } ?>