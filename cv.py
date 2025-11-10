import cv2

# 加载预训练的人脸检测分类器
# 您需要将 'haarcascade_frontalface_default.xml' 替换为实际的分类器文件路径。
# 这个文件通常可以在 OpenCV 的安装目录下找到，或者从 OpenCV 的 GitHub 仓库下载。
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# 检查分类器是否成功加载
if face_cascade.empty():
    print("错误：无法加载人脸检测分类器。请确保 'haarcascade_frontalface_default.xml' 文件存在且路径正确。")
    exit()

# 打开默认摄像头
cap = cv2.VideoCapture(0)

# 检查摄像头是否成功打开
if not cap.isOpened():
    print("错误：无法打开摄像头。请检查摄像头是否连接正确或被其他程序占用。")
    exit()

while True:
    # 读取一帧
    ret, frame = cap.read()

    if not ret:
        print("错误：无法从摄像头读取帧。")
        break

    # 将帧转换为灰度图，人脸检测通常在灰度图上进行
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # 在灰度图上检测人脸
    # scaleFactor: 图像缩小的比例，每次检测窗口扩大多少
    # minNeighbors: 每个候选矩形应该保留多少个邻近元素
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    # 在检测到的人脸周围绘制矩形
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)

    # 显示结果帧
    cv2.imshow('人脸检测', frame)

    # 按 'q' 键退出循环
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放摄像头并关闭所有OpenCV窗口
cap.release()
cv2.destroyAllWindows()
