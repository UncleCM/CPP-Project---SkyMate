// // import QtQuick 2.0
// // import QtQuick.Controls 2.12
// // import QtLocation 5.12
// // import QtPositioning 5.12

// // ApplicationWindow {
// //     visible: true
// //     width: 800
// //     height: 600

// //     Plugin {
// //         id: mapPlugin
// //         name: "mapbox"
// //         PluginParameter {
// //             name: "mapbox.access_token"
// //             value: "YOUR_MAPBOX_ACCESS_TOKEN"
// //         }
// //     }

// //     Map {
// //         id: mapView
// //         anchors.fill: parent
// //         plugin: mapPlugin
// //         center: QtPositioning.coordinate(25.6585, 100.3658);
// //         zoomLevel: 6
// //     }

// //     function setCenter(lat, lng) {
// //         mapView.center = QtPositioning.coordinate(lat, lng);
// //     }

// //     function addMarker(lat, lng) {
// //         var marker = mapMarker.createObject(mapView, {
// //                                            coordinate: QtPositioning.coordinate(lat, lng)
// //                                        });
// //         mapView.addMapItem(marker);
// //     }

// //     Component {
// //         id: mapMarker
// //         MapQuickItem {
// //             anchorPoint.x: image.width/4
// //             anchorPoint.y: image.height
// //             coordinate: position

// //             sourceItem: Image {
// //                 source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
// //             }
// //         }
// //     }
// // }

// ApplicationWindow {
//     visible: true
//     width: 800
//     height: 600

//     Rectangle {
//         width: 800
//         height: 600

//         Image {
//             source: "path/to/your/static/map/image.png"
//             width: 800
//             height: 600
//         }

//         Image {
//             id: marker
//             source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
//             width: 20
//             height: 34
//             visible: false
//         }

//         MouseArea {
//             anchors.fill: parent
//             onClicked: {
//                 var mouseX = mouse.x - marker.width / 2;
//                 var mouseY = mouse.y - marker.height;
//                 marker.x = mouseX;
//                 marker.y = mouseY;
//                 marker.visible = true;
//             }
//         }
//     }
// }
