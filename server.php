// Example script for handling OTA updates on an ESP8266
// Deploy on your web server to serve firmware updates
// Make sure to set the correct permissions for the firmware file

<?php
$firmwareFile = 'ESP8266_Arduino_OTA.ino.bin';
$firmwarePath = __DIR__ . '/' . $firmwareFile;

if (!file_exists($firmwarePath)) {
        http_response_code(404);
        echo 'Firmware not found.';
        exit;
}

// Get client and server firmware MD5
$clientMD5 = $_SERVER['HTTP_X_ESP8266_SKETCH_MD5'] ?? '';
$serverMD5 = md5_file($firmwarePath);

if ($clientMD5 === $serverMD5) {
        http_response_code(304);
        echo 'Already up-to-date.';
        exit;
}

$filesize = filesize($firmwarePath);
header('Content-Type: application/octet-stream');
header('Content-Disposition: attachment; filename="' . $firmwareFile . '"');
header('Content-Length: ' . $filesize);
header('x-MD5: ' . $serverMD5);
readfile($firmwarePath);
?>
