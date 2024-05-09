import os
import cv2
import torch

import numpy as np
import matplotlib.pyplot as plt

from PIL import Image, ImageDraw

class Detector:
  def __init__(self, label, threshold=0.0):
    self.label = label #'stop sign' or 'traffic light'
    # self.model = torch.hub.load('ultralytics/yolov5', 'yolov5n', pretrained=True)
    self.model = torch.hub.load('/root/.yolo', 'custom', source='local', path='/root/.yolo/yolov5n.pt', force_reload=False)
    self.threshold = threshold
    self.results = None

  def predict(self, img):
    """
    Takes in a path or numpy array representing an image
    returns whether or not there is a stop sign, along with the bounding box surrounding it
    """

    if type(img) == str:
      # Path has been passed in
      img_path = img
      img = read_image(img_path)

    results = self.model(img)
    results_df = results.pandas().xyxy[0]
    self.results = results_df

    return self.is_stop_sign(results_df), self.get_bounding_box(results_df)

  def draw_box(self, img, box=None):
    if box is None: _, box = self.predict(img)
    box_img = draw_box(img, box)
    return box_img

  def set_threshold(self, new_thresh):
    self.threshold=new_thresh

  def is_stop_sign(self, df):
    confidences = df[df['confidence'] > self.threshold]
    return len(confidences[confidences['name'] == self.label]) != 0 # If a stop sign has been detected

  def get_bounding_box(self, df):
    if not self.is_stop_sign(df): return [0, 0, 0, 0]
    confidences = df[df['confidence'] > self.threshold]
    stop_sign = confidences[confidences['name'] == self.label].head(1)
    coords = stop_sign.xmin, stop_sign.ymin, stop_sign.xmax, stop_sign.ymax
    return [coord.values[0] for coord in coords]



# Utilities

# Image
def read_image(path):
    rgb_im = cv2.cvtColor(cv2.imread(str(path)), cv2.COLOR_BGR2RGB)
    return rgb_im

def draw_rect(im, xmin, ymin, xmax, ymax):
    box = xmin, ymin, xmax, ymax
    img = Image.fromarray(im)
    imgd = ImageDraw.Draw(img)
    imgd.rectangle(box, outline='red')
    return img

def draw_box(im, box):
    img = Image.fromarray(im)
    imgd = ImageDraw.Draw(img)
    imgd.rectangle(box, outline='red')
    return img

if __name__=="__main__":
    detector = StopSignDetector()
