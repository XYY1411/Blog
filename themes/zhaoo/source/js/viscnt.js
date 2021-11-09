let hostname = location.hostname;
let pathname = location.pathname;
let url = "https://api.xyy1411.top/tools/viscnt/?hostname="
           + hostname + "&pathname=" + pathname;
$.get(url, function(result) {
    $("#pagecnt").html(result);
});
url = "https://api.xyy1411.top/tools/viscnt/?hostname="
           + hostname + "&pathname=@";
$.get(url, function(result) {
    $("#sitecnt").html(result);
});