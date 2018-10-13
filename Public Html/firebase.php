<?php
// Constants
$FIREBASE = "https://carparkingdemo.firebaseio.com/";
$NODE_DELETE = "temperature.json";
$NODE_GET = "temperature.json";
$NODE_PATCH = "carinfo.json";
$NODE_PUT = "temperature.json";
// Data for PUT
// Node replaced
$data1 = $_GET["car1"];
$data2 = $_GET["car2"];
$data3 = $_GET["car3"];
$data4 = $_GET["car4"];

if($data1 == null){
    $data1 = 0;
}

if($data2 == null){
    $data2 = 0;
}

if($data3 == null){
    $data3 = 0;
}

if($data4 == null){
    $data4 = 0;
}
// Data for PATCH
// Matching nodes updated
$data = array(
    "car1" => (int)$data1,
    "car2" => (int)$data2,
    "car3" => (int)$data3,
    "car4" => (int)$data4
);

// JSON encoded
$json = json_encode( $data );
// Initialize cURL
$curl = curl_init();
// Create
// curl_setopt( $curl, CURLOPT_URL, $FIREBASE . $NODE_PUT );
// curl_setopt( $curl, CURLOPT_CUSTOMREQUEST, "PUT" );
// curl_setopt( $curl, CURLOPT_POSTFIELDS, 32 );
// Read
// curl_setopt( $curl, CURLOPT_URL, $FIREBASE . $NODE_GET );
// Update
curl_setopt( $curl, CURLOPT_URL, $FIREBASE . $NODE_PATCH );
curl_setopt( $curl, CURLOPT_CUSTOMREQUEST, "PATCH" );
curl_setopt( $curl, CURLOPT_POSTFIELDS, $json );
// Delete
// curl_setopt( $curl, CURLOPT_URL, $FIREBASE . $NODE_DELETE );
// curl_setopt( $curl, CURLOPT_CUSTOMREQUEST, "DELETE" );
// Get return value
curl_setopt( $curl, CURLOPT_RETURNTRANSFER, true );
// Make request
// Close connection
$response = curl_exec( $curl );
curl_close( $curl );
// Show result
echo $response . "\n";
?>