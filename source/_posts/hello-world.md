---
title: 'Hello World'
author: XYY1411
copyright:
  enable: true
  type: 'CC BY-NC-SA 4.0'
  url: 'https://creativecommons.org/licenses/by-nc-sa/4.0/deed.zh'
carrier: false
description: ''
keywords: ''
image: '/images/ice-flower.jpg'
date: '2021-10-09 21:37:38'
abbrlink: 16107
---

新博客做好了，还在添加更多功能。

<script>
let hostname = location.hostname;
let pathname = location.pathname;
function getPageCnt() {
    let url = "https://api.xyy1411.top/tools/viscnt/?hostname="
               + hostname + "&pathname=" + pathname;
    let text = "";
    $.get(url, function(result) {
        text = result;
    });
    return text;
}
</script>
<div id="cntsss"></div>
<script>$("#cntsss").html(getPageCnt());</script>