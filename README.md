# Mytracks
Qt开发——Mytracks旅行分享项目

项目由5人小组在短短几天内敏捷开发，为软件工程实践作品。软件设计初衷为旅行图片、轨迹、日志分享。地图功能使用百度地图API，具体代码位于res/html/map.html中。由于时间仓促，许多功能尚未完善。

#### 注意事项： ####

* 本项目使用Mysql数据库，配置文件位于mysql.cpp中，运行前需创建“tong_you”数据库。

* “个人信息”功能尚未连接数据库，只是个壳子。

* 上传的图片需有exif信息。

* widgit.cpp中的get_info()函数中需自行根据图片上传的路径将绝对路径转为相对路径。

* 若想图片带有描述，上传图片需先添加描述再上传图片。

* “保存路径”保存的文件为txt文件，“浏览记录”需要导入txt文件。

* 在res/test中附带三张有exif信息的测试图片。

运行效果：
![image](https://github.com/whsyourdaddy/Mytracks/raw/master/login.png)
![image](https://github.com/whsyourdaddy/Mytracks/raw/master/main_menu.png)
![image](https://github.com/whsyourdaddy/Mytracks/raw/master/track.png)
