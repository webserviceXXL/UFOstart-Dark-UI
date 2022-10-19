<?php
$authorized = (isset($_POST['apikey'])) ? true : false;
?>

<!DOCTYPE html>
<html lang="en" class="auto-scaling-disabled">
<head>
  <!-- Meta tags -->
  <meta charset="utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
  <meta content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0" name="viewport" />
  <meta name="viewport" content="width=device-width" />

  <!-- Favicon and title -->
  <title>UFOstart Flightplan</title>

  <!-- Halfmoon CSS -->
  <link href="https://cdn.jsdelivr.net/npm/halfmoon@1.1.1/css/halfmoon-variables.min.css" rel="stylesheet" />
  <link href="css.css" rel="stylesheet" />
</head>
<body class="with-custom-webkit-scrollbars with-custom-css-scrollbars dark-mode" data-dm-shortcut-enabled="true" data-set-preferred-mode-onload="true">
  <!-- Modals go here -->
  <!-- Reference: https://www.gethalfmoon.com/docs/modal -->

  <!-- Page wrapper start -->
  <div class="page-wrapper with-navbar">

    <!-- Sticky alerts (toasts), empty container -->
    <!-- Reference: https://www.gethalfmoon.com/docs/sticky-alerts-toasts -->
    <div class="sticky-alerts"></div>

    <!-- Navbar start -->
    <nav class="navbar">
      <!-- Navbar brand -->
      <a href="<?="//".$_SERVER[HTTP_HOST].$_SERVER[REQUEST_URI]?>" class="navbar-brand">
        <img src="https://assets.website-files.com/600efa38a5bbff0b655b71f1/60111a18416e071e3d660fed_UFOstart-logo.svg" alt="UFOstart logo">
        UFOstart
      </a>
      <!-- Navbar nav -->
      <ul class="navbar-nav">
        <?php if(!$authorized) : ?>
        <li class="nav-item active">
          <a href="#" class="nav-link">Login</a>
        </li>
        <?php else : ?>
        <!--
        <li class="nav-item active">
          <a href="#" class="nav-link">Your Flighplan</a>
        </li>
        -->
        <?php endif; ?>
      </ul>
      <a class="btn ml-auto" href="https://discord.gg/ufostart" target="_blank">Discord</a>
      <button class="btn btn-action ml-5" type="button" onclick="halfmoon.toggleDarkMode()" aria-label="Toggle dark mode">☼</button>
    </nav>
    <!-- Navbar end -->

    <!-- Content wrapper start -->
    <div class="content-wrapper">
        <?php if($authorized) : ?>
            <?php  require 'actions.inc' ?>
        <?php else : ?>
        <div class="container-fluid">
            <!-- First row -->
            <div class="row justify-content-center">
                <div class="col-12 col-sm-10 col-md-8 col-lg-4">
                    <div class="my-20 text-center">
                        <h1>Authenticate</h1>
                    </div>
                    <div class="card">
                        <!-- Inline form with form-groups -->
                        <form action="<?="//".$_SERVER[HTTP_HOST].$_SERVER[REQUEST_URI]?>" method="post" class="form-inline mw-full">
                            <div class="form-group">
                                <label class="required w-80" for="password">API key</label>
                                <input type="password" class="form-control" placeholder="API key" id="password" required="required" name="apikey">
                            </div>
                            <div class="form-group mb-0">
                                <input type="submit" class="btn btn-block btn-primary ml-auto" value="Sign in">
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
        <?php endif; ?>

        <div class="container">
            <div class="row">
                <div class="col-12 text-center">
                    <span class="font-size-11 text-monospace">Flightplan UI v0.1</span>
                    <br />
                    <span class="font-size-11 text-monospace"><a href="https://heiko.vogelgesang.berlin">Heiko.Vogelgesang.Berlin</a></span>
                    <br />
                    <span class="font-size-11 font-weight-bold text-monospace"><a href="https://www.ufostart.com">UFOstart</a></span>
                </div>
            </div>
        </div>
    </div>
    <!-- Content wrapper end -->

  </div>
  <!-- Page wrapper end -->

  <!-- Halfmoon JS -->
  <script src="https://cdn.jsdelivr.net/npm/halfmoon@1.1.1/js/halfmoon.min.js"></script>
</body>
</html>