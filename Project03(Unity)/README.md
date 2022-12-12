# 자동차 게임
* Style
```
<style>
  canvas {
    background: #eee;
  }; 
</style>
```

* Body(canvas )
```
<body>
  <canvas id="myCanvas" width="480" height="320"></canvas>
</body>
```

* Script(변수)
```
<script>
  var canvas = document.getElementById("myCanvas");
  var ctx = canvas.getContext("2d");
  var ballRadius = 10;
  var x = canvas.width/2;
  var y = canvas.height-30;
  var dx = 2;
  var dy = -2;
</script>
```



# 출처 및 참조
* [원본](https://www.youtube.com/watch?v=pTc1dakebow)
* [휠 콜라이더 기본 세팅](https://coding-of-today.tistory.com/128)
* [휠 콜라이더 움직임 구현](https://coding-of-today.tistory.com/130)
* [카메라 온오프](https://artiper.tistory.com/106)
* [키 코드](https://wergia.tistory.com/211)
* [속도 감속](https://micropilot.tistory.com/2656)
* [오디오](https://202psj.tistory.com/1312)
* [각각의 업데이트](http://developug.blogspot.com/2014/09/update-fixedupdate-lateupdate.html)
* [구조체+맵](https://assetstore.unity.com/packages/3d/environments/industrial/rpg-fps-game-assets-for-pc-mobile-industrial-set-v2-0-86679)
* [사운드](https://assetstore.unity.com/packages/audio/sound-fx/transportation/i6-german-free-engine-sound-pack-106037)
* [자동차](https://assetstore.unity.com/packages/3d/vehicles/land/hq-racing-car-model-no-1203-139221)
