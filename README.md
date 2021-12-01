# SudaCgMFC

#### 介绍
苏州大学计算机图形学课程实验
包含二维点类三维点类的建立，面类，二维变换，
三维变换，zbuffer，背面剔除，反走样划线，
颜色填充，模型数据文件读入

#### 软件架构说明

├── Readme.md  
├── LICENSE                 
├── .gitignore                        
├── Debug                     
│&emsp;&emsp;├── Test4.exe<br/>
│&emsp;&emsp;├── Test4.ilk              
│&emsp;&emsp;├── Test4.pdb        
├── Test4<br/>
│&emsp;&emsp;├── Debug              
│&emsp;&emsp;├── res<br/>
│&emsp;&emsp;├── 模型数据文档<br/>
│&emsp;&emsp;│&emsp;&emsp;├── 1.txt           //人脸数据<br/>
│&emsp;&emsp;│&emsp;&emsp;├── 3.txt           //马头数据         
│&emsp;&emsp;├── 基本元素<br/>
│&emsp;&emsp;│&emsp;&emsp;├── RGB.h<br/>
│&emsp;&emsp;│&emsp;&emsp;├── RGB.cpp      
│&emsp;&emsp;│&emsp;&emsp;├── P2.h            //二维点类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── P2.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── P3.h            //三维点类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── P3.cpp <br/>
│&emsp;&emsp;│&emsp;&emsp;├── Transform2.h    //二维变换类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Transform2.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Transform3.h    //三维变换类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Transform3.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Facet.h         //面类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Facet.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Vector.h        //向量类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Vector.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Projection.h    //投影类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Projection.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── CLine.h         //线绘制<br/>
│&emsp;&emsp;│&emsp;&emsp;├── CLine.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Point2.h        //二维点类（整型）<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Point2.cpp <br/>
│&emsp;&emsp;│&emsp;&emsp;├── Point3.h        //三维点类（整型）<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Point3.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Triangle.h      //三角形填充类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Triangle.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── ZBuffer.h       //消隐<br/>
│&emsp;&emsp;│&emsp;&emsp;├── ZBuffer.cpp<br/>
│&emsp;&emsp;├── 图形类    <br/>
│&emsp;&emsp;│&emsp;&emsp;├── CStar.h         //五角星<br/>
│&emsp;&emsp;│&emsp;&emsp;├── CStar.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Cube.h          //立方体<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Cube.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Fence.h         //没啥用，测试用的图形<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Fence.cpp <br/>
│&emsp;&emsp;│&emsp;&emsp;├── Read1.h         //3.txt<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Read1.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Read2.h         //1.txt<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Read2.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Sphere.h        //球类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Sphere.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Xin.h           //独孤信印章<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Xin.cpp          <br/>
│&emsp;&emsp;├── MFC自建类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── framework.h<br/>
│&emsp;&emsp;│&emsp;&emsp;├── framework.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── MainFrm.h <br/>
│&emsp;&emsp;│&emsp;&emsp;├── MainFrm.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── resource.h<br/>
│&emsp;&emsp;│&emsp;&emsp;├── targetver.h<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4.aps<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4.cpp <br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4.h<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4.rc <br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4.vcxproj<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4.vcxproj.filters<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4.vcxproj.user<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4Doc.h <br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4Doc.cpp<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4View.h     //绘图主类<br/>
│&emsp;&emsp;│&emsp;&emsp;├── Test4View.cpp <br/>
└── Test4.sln<br/>

#### 使用说明


#### 关于作者
赵龙辉<br/>
邮箱：1548715169@qq.com<br/>

该项目<video src="C:\GitProjects\SudaCgMFC\test.mp4"></video>参考了孔令德《三维计算机图形学》<br/>

<video src="C:\GitProjects\SudaCgMFC\test.mp4"></video>

